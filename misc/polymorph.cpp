#include <stdio.h>

/* an object points to its Class... */
struct Animal {
    const struct AnimalClass* Class;
};

/* which contains the virtual function Animal.Eat */
// like a vtable
struct AnimalClass {
    void (*Eat)(struct Animal *); // 'virtual' function
};

/* Since Animal.Move is not a virtual function
   it is not in the structure above. */
void Move(struct Animal * self)
{
    printf("<Animal at %p> moved in some way\n", (void *) self);
}

/* unlike Move, which executes Animal.Move directly,
   Eat cannot know which function (if any) to call at compile time.
   Animal.Eat can only be resolved at run time when Eat is called. */
void Eat(struct Animal * self)
{
    // get the Animal Class pointer from struct pointer;
    const struct AnimalClass * Class = *(const AnimalClass **) self;
    if (Class->Eat)
        // execute Animal.Eat
        Class->Eat(self);
    else
        fprintf(stderr, "Eat not implemented\n");
}

/* implementation of Llama.Eat this is the target function
   to be called by 'void Eat(struct Animal *).' */
static void _Llama_eat(struct Animal * self)
{
    printf("<Llama at %p> Llama's eat grass!\n", (void *) self);
}

/* initialize Class */
const struct AnimalClass Animal = {nullptr}; // base Class does not implement Animal.Eat
const struct AnimalClass Llama = {.Eat = _Llama_eat};  // but the derived Class does

int main(void)
{
    /* init objects as instance of its Class */
    struct Animal animal = {& Animal};
    struct Animal llama = {& Llama};
    Move(& animal); // Animal.Move
    Move(& llama);  // Llama.Move
    Eat(& animal);  // cannot resolve Animal.Eat so print "Not Implemented" to stderr
    Eat(& llama);   // resolves Llama.Eat and executes
}