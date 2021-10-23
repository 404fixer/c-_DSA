#include <bits/stdc++.h>

using namespace std;

// this allows deletion assuming you are using a container
// where erasing some element only invalidates iterators
// pointing to that element (for example set and map)
#define ITER_FOR(name, container) \
  for (auto name = begin(container), \
            _nxt = (name != end(container) ? next(name) : name); \
            name != end(container); \
            name = _nxt, _nxt = (name != end(container) ? next(name) : name))

int main() {
  cin.tie(0)->sync_with_stdio(0);

  set<int> s {0, 1, 2, 3, 4, 5};

  ITER_FOR(it, s) {
    cout << *it << ' ';
    if (*it % 2)
      s.erase(it);
  }
  cout << '\n';

  ITER_FOR(it, s)
    cout << *it << ' ';
  cout << '\n';
}