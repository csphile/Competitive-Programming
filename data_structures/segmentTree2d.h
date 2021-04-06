//
// Created by gael on 25/03/2021.
//
template<typename T>
class SegTree2D {
		int n, m;
		vector<vector<T>> t, a;
		static constexpr T unit = make_pair(-1e18, 1e18);
public:
		SegTree2D(vector <vector<T>> &data) : n(data.size()), m(data[0].size()), a(data) {
			t = vector < vector < T >> (4 * n + 13, vector<T>(4 * m + 13));
			build_x(1, 0, n - 1);
		}

		void _build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
			if (ly == ry) {
				if (lx == rx)
					t[vx][vy] = a[lx][ly];
				else
					t[vx][vy] = f(t[vx * 2][vy], t[vx * 2 + 1][vy]);
			} else {
				int my = (ly + ry) / 2;
				_build_y(vx, lx, rx, 2 * vy, ly, my);
				_build_y(vx, lx, rx, 2 * vy + 1, my + 1, ry);
				t[vx][vy] = f(t[vx][2 * vy], t[vy][2 * vy + 1]);
			}
		}

		void build_x(int vx, int lx, int rx) {
			if (lx != rx) {
				int mx = (lx + rx) / 2;
				build_x(2 * vx, lx, mx);
				build_x(2 * vx + 1, mx + 1, rx);
			}
			_build_y(vx, lx, rx, 1, 0, m - 1);
		}

		T f(T t1, T t2) {
			// for any associative function f;
			return make_pair(max(t1.first, t2.first), min(t1.second, t2.second));
		}

		T query_y(int vx, int vy, int tly, int try_, int ly, int ry) {
			// ly and ry is the queried range
			if (ly > ry)
				return unit;
			if (ly == tly && try_ == ry)
				return t[vx][vy];
			int tmy = (tly + try_) / 2;
			return f(query_y(vx, vy * 2, tly, tmy, ly, min(ry, tmy)),
			         query_y(vx, vy * 2 + 1, tmy + 1, try_, max(ly, tmy + 1), ry));
		}

		T query_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
			// ly, ry, lx, rx is the queried range
			if (lx > rx)
				return unit;
			if (tlx == trx)
				return query_y(vx, 1, 0, m - 1, ly, ry);
			int tmx = (tlx + trx) / 2;
			return f(query_x(vx * 2, tlx, tmx, lx, min(rx, tmx), ly, ry),
			         query_x(vx * 2 + 1, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry));
		}

		void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, T new_val) {
			if (ly == ry) {
				if (lx == rx)
					t[vx][vy] = new_val;
				else
					t[vx][vy] = f(t[vx * 2][vy], t[vx * 2 + 1][vy]);
			} else {
				int my = (ly + ry) / 2;
				if (y <= my)
					update_y(vx, lx, rx, vy * 2, ly, my, x, y, new_val);
				else
					update_y(vx, lx, rx, vy * 2 + 1, my + 1, ry, x, y, new_val);
				t[vx][vy] = f(t[vx][vy * 2], t[vx][vy * 2 + 1]);
			}
		}

		void update_x(int vx, int lx, int rx, int x, int y, T new_val) {
			if (lx != rx) {
				int mx = (lx + rx) / 2;
				if (x <= mx)
					update_x(vx * 2, lx, mx, x, y, new_val);
				else
					update_x(vx * 2 + 1, mx + 1, rx, x, y, new_val);
			}
			update_y(vx, lx, rx, 1, 0, m - 1, x, y, new_val);
		}
};

