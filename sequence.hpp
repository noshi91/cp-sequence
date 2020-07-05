
/*

template <class T> class sequence {
public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  class iterator;
  class const_iterator;
  using size_type = std::size_t;
  using difference_type = std::ptrdiff_t;
  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;

  constexpr Seq();
  explicit Seq(size_type n);
  explicit Seq(size_type n, const T &value);
  template <class InputIterator> Seq(InputIterator first, InputIterator last);
  Seq(Seq &&x) noexcept;
  Seq(std::initializer_list<T> il);

  ~Seq();

  Seq &operator=(const Seq &x);
  Seq &operator=(Seq &&x);
  Seq &operator=(std::initializer_list<T> il);

  template <class InputIterator>
  void assign(InputIterator first, InputIterator last);
  void assign(size_type n, const T &u);
  void assign(std::initializer_list<T> il);

  iterator begin() noexcept;
  const_iterator begin() const noexcept;
  iterator end() noexcept;
  const_iterator end() const noexcept;

  reverse_iterator rbegin() noexcept;
  const_reverse_iterator rbegin() const noexcept;
  reverse_iterator rend() noexcept;
  const_reverse_iterator rend() const noexcept;

  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;
  const_reverse_iterator crbegin() const noexcept;
  const_reverse_iterator crend() const noexcept;

  iterator nth_iterator(size_type n);

  const_iterator nth_iterator(size_type n) const;

  size_type size() const noexcept;
  bool empty() const noexcept;

  T &operator[](size_type n);
  const T &operator[](size_type n) const;
  T &at(size_type n);
  const T &at(size_type n) const;

  T &front();
  const T &front() const;
  T &back();
  const T &back() const;

  void push_back(const value_type &x);
  void push_back(value_type &&x);
  template <class... Args> T &emplace_back(Args &&... args);
  void pop_back();

  void push_front(const value_type &x);
  void push_front(value_type &&x);
  template <class... Args> reference emplace_front(Args &&... args);
  void pop_front();

  template <class... Args>
  iterator emplace(const_iterator position, Args &&... args);
  iterator insert(const_iterator position, const T &x);
  iterator insert(const_iterator position, T &&x);
  iterator insert(const_iterator position, size_type n, const T &x);
  template <class InputIterator>
  iterator insert(const_iterator position, InputIterator first,
                  InputIterator last);
  iterator insert(const_iterator position, std::initializer_list<T> il);

  iterator erase(const_iterator position);
  iterator erase(const_iterator first, const_iterator last);
  void clear();

  void resize(size_type n);
  void resize(size_type n, const T &value);

  void swap(Seq &x) noexcept;

  void splice(const_iterator position, Seq &x);
  void splice(const_iterator position, Seq &&x);
  void splice(const_iterator position, Seq &x, const_iterator i);
  void splice(const_iterator position, Seq &&x, const_iterator i);
  void splice(const_iterator position, Seq &x, const_iterator first,
              const_iterator last);
  void splice(const_iterator position, Seq &&x, const_iterator first,
              const_iterator last);
  void reverse() noexcept;

  class iterator {
  public:
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T *;
    using reference = T &;
    using iterator_category = std::random_access_iterator_tag;

    iterator();

    bool is_initialized() const;

    bool is_end() const;

    Seq &from() const;

    size_type position() const;

    template <class... Args> iterator emplace(Args &&... args) const;
    iterator insert(const T &x) const;
    iterator insert(T &&x) const;
    iterator insert(size_type n, const T &x);
    template <class InputIterator>
    iterator insert(InputIterator first, InputIterator last);
    iterator insert(std::initializer_list<T> il);

    iterator erase();

    void splice(Seq &x);
    void splice(Seq &&x);
    void splice(iterator i);
    void splice(iterator first, iterator last);

    T &operator*() const;
    T *operator->() const;
    T &operator[](difference_type n) const;
    iterator &operator++();
    iterator operator++(int);
    iterator &operator--();
    iterator operator--(int);
    iterator &operator+=(difference_type n);
    iterator &operator-=(difference_type n);

    friend iterator operator+(const iterator &it, difference_type n);
    friend iterator operator+(difference_type n, const iterator &it);
    friend iterator operator-(const iterator &it, difference_type n);
    friend difference_type operator-(const iterator &lhs, const iterator &rhs);

    friend void swap(iterator &lhs, iterator &rhs);

    friend bool operator==(const iterator &lhs, const iterator &rhs);
    friend bool operator!=(const iterator &lhs, const iterator &rhs);
    friend bool operator<(const iterator &lhs, const iterator &rhs);
    friend bool operator<=(const iterator &lhs, const iterator &rhs);
    friend bool operator>(const iterator &lhs, const iterator &rhs);
    friend bool operator>=(const iterator &lhs, const iterator &rhs);
  };

  class const_iterator {
  public:
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = const T *;
    using reference = const T &;
    using iterator_category = std::random_access_iterator_tag;

    const_iterator();

    const Seq &from() const;

    size_type position() const;

    const T &operator*() const;
    const T *operator->() const;
    const T &operator[](difference_type n) const;
    const_iterator &operator++();
    const_iterator operator++(int);
    const_iterator &operator--();
    const_iterator operator--(int);
    const_iterator &operator+=(difference_type n);
    const_iterator &operator-=(difference_type n);

    friend const_iterator operator+(const const_iterator &it,
                                    difference_type n);
    friend const_iterator operator+(difference_type n,
                                    const const_iterator &it);
    friend const_iterator operator-(const const_iterator &it,
                                    difference_type n);
    friend difference_type operator-(const const_iterator &lhs,
                                     const const_iterator &rhs);

    friend void swap(const_iterator &lhs, const_iterator &rhs);

    friend bool operator==(const const_iterator &lhs,
                           const const_iterator &rhs);
    friend bool operator!=(const const_iterator &lhs,
                           const const_iterator &rhs);
    friend bool operator<(const const_iterator &lhs, const const_iterator &rhs);
    friend bool operator<=(const const_iterator &lhs,
                           const const_iterator &rhs);
    friend bool operator>(const const_iterator &lhs, const const_iterator &rhs);
    friend bool operator>=(const const_iterator &lhs,
                           const const_iterator &rhs);
  };
};

*/

#include <cstddef>
#include <initializer_list>
#include <iterator>
#include <memory>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

//*
#include <iostream>
#include <string>
//*/

template <class T> class sequence_impl {
  using usize = std::size_t;
  using isize = std::ptrdiff_t;

public:
  class Seq;

private:
  class Node;
  class NodeBase;
  class Iter;
  class IterMut;

  class NodeBase {
    friend sequence_impl;

  private:
    NodeBase *parent;

    NodeBase() : parent(nullptr) {}

    bool is_end() const { return !parent; }

    Node *to_node() { return static_cast<Node *>(this); }
    Seq *to_seq() { return static_cast<Seq *>(this); }
  };

  class SeqBuilder {
    std::vector<std::unique_ptr<Node>> vec;

  public:
    template <class... Args> void add(Args &&... args) {
      std::unique_ptr<Node> temp;
      usize i = 0;
      while (i != vec.size() && vec[i]) {
        set_child<true>(vec[i].get(), std::move(temp));
        vec[i]->fix();
        temp = std::move(vec[i]);
        i += 1;
      }
      if (i == vec.size()) {
        vec.emplace_back();
      }
      auto elem = std::make_unique<Node>(std::forward<Args>(args)...);
      set_child<false>(elem.get(), std::move(temp));
      vec[i] = std::move(elem);
    }

    std::unique_ptr<Node> build() {
      std::unique_ptr<Node> temp;
      for (auto &e : vec) {
        if (e) {
          set_child<true>(e.get(), std::move(temp));
          e->fix();
          temp = std::move(e);
        }
      }
      return std::move(temp);
    }
  };

  template <class F> class SplayHelper {
  public:
    template <bool Side> class Inner {
    public:
      std::unique_ptr<Node> subtree;
      NodeBase *parent;
      std::unique_ptr<Node> *next;

      Inner() : subtree(), parent(nullptr), next(&subtree) {}

      void add(std::unique_ptr<Node> ptr) {
        ptr->parent = parent;
        parent = ptr.get();
        *next = std::move(ptr);
        next = &child<!Side>(next->get());
      }

      std::unique_ptr<Node> build() {
        while (parent) {
          parent->to_node()->fix();
          parent = parent->to_node()->parent;
        }
        return std::move(subtree);
      }

      std::unique_ptr<Node> build(std::unique_ptr<Node> ptr) {
        if (ptr) {
          ptr->parent = parent;
          *next = std::move(ptr);
        }
        return build();
      }
    };

    F f;
    std::unique_ptr<Node> ptr, temp;
    std::pair<Inner<false>, Inner<true>> state;

    SplayHelper(std::unique_ptr<Node> &&ptr, F &&f)
        : f(std::move(f)), ptr(std::move(ptr)) {}

    template <bool Side0, bool Side1> void double_rotate() {
      temp->push();
      if (Side0 == Side1) {
        set_child<Side0>(ptr.get(), std::move(child<!Side1>(temp.get())));
        ptr->fix();
        set_child<!Side1>(temp.get(), std::move(ptr));
        ptr = std::move(child<Side1>(temp.get()));
        std::get<!Side1>(state).add(std::move(temp));
      } else {
        std::get<!Side0>(state).add(std::move(ptr));
        ptr = std::move(child<Side1>(temp.get()));
        std::get<!Side1>(state).add(std::move(temp));
      }
    }

    template <bool Side> bool sub() {
      ptr->push();
      temp = std::move(child<Side>(ptr.get()));
      switch (f(temp.get())) {
      case -1: {
        double_rotate<Side, false>();
        return false;
      } break;
      case 0: {
        std::get<!Side>(state).add(std::move(ptr));
        ptr = std::move(temp);
        return true;
      } break;
      case 1: {
        double_rotate<Side, true>();
        return false;
      } break;
      }
      return false;
    }

    void splay() {
      while (true) {
        switch (f(ptr.get())) {
        case -1: {
          if (sub<false>()) {
            return;
          }
        } break;
        case 0: {
          return;
        } break;
        case 1: {
          if (sub<true>()) {
            return;
          }
        } break;
        }
      }
    }

    template <bool Side> void set_non_null() {
      set_child<Side>(ptr.get(), std::get<Side>(state).build(
                                     std::move(child<Side>(ptr.get()))));
    }

    void build_non_null() {
      ptr->push();
      set_non_null<false>();
      set_non_null<true>();
      ptr->fix();
    }
  };

  template <class InputIterator>
  using IterCheck = typename std::enable_if<
      std::is_base_of<std::input_iterator_tag,
                      typename std::iterator_traits<
                          InputIterator>::iterator_category>::value &&
          std::is_constructible<T, typename std::iterator_traits<
                                       InputIterator>::reference>::value,
      InputIterator>::type;

public:
  class Seq : public NodeBase {
    friend sequence_impl;

  public:
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using iterator = IterMut;
    using const_iterator = Iter;
    using size_type = usize;
    using difference_type = isize;
    using reverse_iterator = std::reverse_iterator<IterMut>;
    using const_reverse_iterator = std::reverse_iterator<Iter>;

  private:
    mutable std::unique_ptr<Node> root;

    void set_root(std::unique_ptr<Node> &&ptr) {
      root = std::move(ptr);
      if (root) {
        root->parent = this;
      }
    }

    Seq &remove_const() const { return const_cast<Seq &>(*this); }

  public:
    void dump() const {
      std::cout << "--- Seq debug ---\n";
      print_tree(root.get(), 0);
      std::cout << "--- Seq debug ---\n";
    }

    constexpr Seq() = default;
    explicit Seq(usize n) : Seq(n, T()) {}
    explicit Seq(usize n, const T &value) {
      SeqBuilder b;
      for (usize i = 0; i != n; ++i) {
        b.add(value);
      }
      set_root(b.build());
    }
    template <class InputIterator>
    Seq(InputIterator first, IterCheck<InputIterator> last) {
      SeqBuilder b;
      while (first != last) {
        b.add(*first++);
      }
      set_root(b.build());
    }
    Seq(const Seq &x) {
      SeqBuilder b;
      copy_tree(x.root.get(), b);
      set_root(b.build());
    }
    Seq(Seq &&x) noexcept { *this = std::move(x); }
    Seq(std::initializer_list<T> il) : Seq(il.begin(), il.end()) {}

    ~Seq() = default;

    Seq &operator=(const Seq &x) { return *this = Seq(x); }
    Seq &operator=(Seq &&x) noexcept {
      set_root(std::move(x.root));
      return *this;
    }
    Seq &operator=(std::initializer_list<T> il) { return *this = Seq(il); }

    template <class InputIterator>
    void assign(InputIterator first, IterCheck<InputIterator> last) {
      *this = Seq(first, last);
    }
    void assign(usize n, const T &u) { *this = Seq(n, u); }
    void assign(std::initializer_list<T> il) {
      *this = Seq(il.begin(), il.end());
    }

    IterMut begin() noexcept {
      if (empty()) {
        return end();
      } else {
        splay_nth(root, 0);
        return root.get();
      }
    }
    Iter begin() const noexcept { return remove_const().begin(); }
    IterMut end() noexcept { return this; }
    Iter end() const noexcept { return remove_const().end(); }

    reverse_iterator rbegin() noexcept { return reverse_iterator(end()); }
    const_reverse_iterator rbegin() const noexcept {
      return const_reverse_iterator(end());
    }
    reverse_iterator rend() noexcept { return reverse_iterator(begin()); }
    const_reverse_iterator rend() const noexcept {
      return const_reverse_iterator(begin());
    }

    Iter cbegin() const noexcept { return begin(); }
    Iter cend() const noexcept { return end(); }
    const_reverse_iterator crbegin() const noexcept {
      return const_reverse_iterator(cend());
    }
    const_reverse_iterator crend() const noexcept {
      return const_reverse_iterator(cbegin());
    }

    IterMut nth_iterator(usize n) {
      if (n == size()) {
        return end();
      } else {
        splay_nth(root, n);
        return root.get();
      }
    }

    Iter nth_iterator(usize n) const { return remove_const().nth_iterator(n); }

    usize size() const noexcept { return size_(root.get()); }
    bool empty() const noexcept { return !root; }

    T &operator[](usize n) {
      splay_nth(root, n);
      return root->value;
    }
    const T &operator[](usize n) const { return remove_const()[n]; }
    T &at(usize n) {
      if (n < size()) {
        return (*this)[n];
      } else {
        throw std::out_of_range(
            "out of range : called `sequence::at` with invalid "
            "index");
      }
    }
    const T &at(usize n) const { return remove_const().at(n); }

    T &front() { return *begin(); }
    const T &front() const { return *begin(); }
    T &back() { return *rbegin(); }
    const T &back() const { return *rbegin(); }

    void push_back(const value_type &x) { emplace_back(x); }
    void push_back(value_type &&x) { emplace_back(std::move(x)); }
    template <class... Args> T &emplace_back(Args &&... args) {
      auto elem = std::make_unique<Node>(std::forward<Args>(args)...);
      set_child<false>(elem.get(), std::move(root));
      elem->fix();
      set_root(std::move(elem));
      return root->value;
    }
    void pop_back() {
      splay_nth(root, size() - 1);
      set_root(std::move(root->left()));
    }

    void push_front(const value_type &x) { emplace_front(x); }
    void push_front(value_type &&x) { emplace_front(std::move(x)); }
    template <class... Args> reference emplace_front(Args &&... args) {
      auto elem = std::make_unique<Node>(std::forward<Args>(args)...);
      set_child<true>(elem.get(), std::move(root));
      elem->fix();
      set_root(std::move(elem));
      return root->value;
    }
    void pop_front() {
      splay_nth(root, 0);
      set_root(std::move(root->right()));
    }

    template <class... Args> IterMut emplace(Iter position, Args &&... args) {
      return position.to_mut().emplace(std::forward<Args>(args)...);
    }
    IterMut insert(Iter position, const T &x) {
      return position.to_mut().insert(x);
    }
    IterMut insert(Iter position, T &&x) {
      return position.to_mut().insert(std::move(x));
    }
    IterMut insert(Iter position, usize n, const T &x) {
      return position.to_mut().insert(n, x);
    }
    template <class InputIterator>
    IterMut insert(Iter position, InputIterator first,
                   IterCheck<InputIterator> last) {
      return position.to_mut().insert(first, last);
    }
    IterMut insert(Iter position, std::initializer_list<T> il) {
      return position.to_mut().insert(il);
    }

    IterMut erase(Iter position) { return position.to_mut().erase(); }
    IterMut erase(Iter first, Iter last) {
      (void)erase_help(first.to_mut(), last.to_mut());
      return last.to_mut();
    }
    void clear() { *this = Seq(); }

    void resize(usize n) { resize(n, T()); }
    void resize(usize n, const T &value) {
      usize s = size();
      if (n < s) {
        erase(nth_iterator(n), end());
      } else {
        insert(end(), s - n, value);
      }
    }

    void swap(Seq &x) noexcept { std::swap(*this, x); }

    void splice(Iter position, Seq &x) { position.to_mut().splice(x); }
    void splice(Iter position, Seq &&x) {
      position.to_mut().splice(std::move(x));
    }
    void splice(Iter position, Seq &x, Iter i) {
      position.to_mut().splice(x, i);
    }
    void splice(Iter position, Seq &&x, Iter i) {
      position.to_mut().splice(std::move(x), i);
    }
    void splice(Iter position, Seq &x, Iter first, Iter last) {
      position.to_mut().splice(x, first, last);
    }
    void splice(Iter position, Seq &&x, Iter first, Iter last) {
      position.to_mut().splice(std::move(x), first, last);
    }
    void reverse() noexcept { sequence_impl::reverse(root.get()); }
  };

private:
  static void splay_nth(std::unique_ptr<Node> &ptr, usize n) {
    NodeBase *par = ptr->parent;
    auto f = [&](Node *p) -> int {
      usize ls = size_(p->left().get());
      if (n < ls) {
        return -1;
      } else if (n == ls) {
        return 0;
      } else {
        n -= ls + 1;
        return 1;
      }
    };
    SplayHelper<decltype(f)> h(std::move(ptr), std::move(f));
    h.splay();
    h.build_non_null();
    ptr = std::move(h.ptr);
    ptr->parent = par;
  }

  class Node : public NodeBase {
    friend sequence_impl;

  public:
    using NodeBase::parent;
    std::pair<std::unique_ptr<Node>, std::unique_ptr<Node>> children;
    usize size;
    bool reversed;
    T value;

    template <class... Args>
    Node(Args &&... args)
        : children(), size(101), reversed(false),
          value(std::forward<Args>(args)...) {}

    std::unique_ptr<Node> &left() { return child<false>(this); }

    std::unique_ptr<Node> &right() { return child<true>(this); }

    void fix() { size = size_(left().get()) + 1 + size_(right().get()); }

    void reverse() {
      left().swap(right());
      reversed = !reversed;
    }

    void push() {
      if (reversed) {
        sequence_impl::reverse(left().get());
        sequence_impl::reverse(right().get());
        reversed = false;
      }
    }
  };

  class IterMut {
    friend sequence_impl;

    using isize = isize;

    NodeBase *ptr;

    IterMut(NodeBase *ptr) : ptr(ptr) {}

  public:
    using difference_type = isize;
    using value_type = T;
    using pointer = T *;
    using reference = T &;
    using iterator_category = std::random_access_iterator_tag;

    IterMut() : ptr(nullptr) {}

    bool is_initialized() const { return ptr; }

    bool is_end() const { return ptr->is_end(); }

    Seq &from() const {
      NodeBase *p = ptr;
      if (!is_end()) {
        splay(p->to_node());
        p = p->parent;
      }
      return *p->to_seq();
    }

    usize position() const {
      if (is_end()) {
        return ptr->to_seq()->size();
      } else {
        Node *node = ptr->to_node();
        splay(node);
        return size_(node->left().get());
      }
    }

    IterMut insert_help(std::unique_ptr<Node> &&x) const {
      if (x) {
        Node *ret = x.get();
        splay_nth(x, 0);
        if (is_end()) {
          Seq *s = ptr->to_seq();
          set_child<false>(x.get(), std::move(s->root));
          x->fix();
          s->set_root(std::move(x));
        } else {
          Node *n = ptr->to_node();
          splay(n);
          set_child<false>(x.get(), std::move(n->left()));
          x->fix();
          set_child<false>(n, std::move(x));
          n->fix();
        }
        return ret;
      } else {
        return *this;
      }
    }

    template <class... Args> IterMut emplace(Args &&... args) const {
      return insert_help(std::make_unique<Node>(std::forward<Args>(args)...));
    }
    IterMut insert(const T &x) const { return emplace(x); }
    IterMut insert(T &&x) const { return emplace(std::move(x)); }
    IterMut insert(usize n, const T &x) { return insert_help(Seq(n, x).root); }
    template <class InputIterator>
    IterMut insert(InputIterator first, IterCheck<InputIterator> last) {
      return insert_help(Seq(first, last).root);
    }
    IterMut insert(std::initializer_list<T> il) {
      return insert_help(Seq(il).root);
    }

    std::pair<IterMut, std::unique_ptr<Node>> erase_help() {
      Node *n = ptr->to_node();
      splay(n);
      Seq *s = n->parent->to_seq();
      auto left = std::move(n->left());
      auto right = std::move(n->right());
      auto mid = std::move(s->root);
      NodeBase *ret;
      if (right) {
        splay_nth(right, 0);
        set_child<false>(right.get(), std::move(left));
        right->fix();
        ret = right.get();
        s->set_root(std::move(right));
      } else {
        s->set_root(std::move(left));
        ret = s;
      }
      return {IterMut(ret), std::move(mid)};
    }

    IterMut erase() { return erase_help().first; }

    void splice(Seq &x) const { insert_help(std::move(x.root)); }
    void splice(Seq &&x) const { insert_help(std::move(x.root)); }
    void splice(Seq &x, Iter i) const { splice(i.to_mut()); }
    void splice(Seq &&x, Iter i) const { splice(i.to_mut()); }
    void splice(IterMut i) const { insert_help(i.erase_help().second); }
    void splice(Seq &x, Iter first, Iter last) const {
      splice(first.to_mut(), last.to_mut());
    }
    void splice(IterMut first, IterMut last) const {
      insert_help(sequence_impl::erase_help(first, last));
    }

    T &operator*() const { return ptr->to_node()->value; }
    T *operator->() const { return &ptr->to_node()->value; }
    T &operator[](isize n) const { return *(*this + n); }
    IterMut &operator++() { return *this += 1; }
    IterMut operator++(int) {
      auto ret = *this;
      ++(*this);
      return ret;
    }
    IterMut &operator--() { return *this -= 1; }
    IterMut operator--(int) {
      auto ret = *this;
      --(*this);
      return ret;
    }
    IterMut &operator+=(isize n) { return *this = *this + n; }
    IterMut &operator-=(isize n) { return *this += -n; }

    friend IterMut operator+(const IterMut &it, isize n) {
      return it.from().nth_iterator(isize(it.position()) + n);
    }
    friend IterMut operator+(isize n, const IterMut &it) { return it + n; }
    friend IterMut operator-(const IterMut &it, isize n) { return it + -n; }
    friend isize operator-(const IterMut &lhs, const IterMut &rhs) {
      return isize(lhs.position()) - isize(rhs.position());
    }

    friend void swap(IterMut &lhs, IterMut &rhs) { std::swap(lhs, rhs); }

    friend bool operator==(const IterMut &lhs, const IterMut &rhs) {
      return lhs.ptr == rhs.ptr;
    }
    friend bool operator!=(const IterMut &lhs, const IterMut &rhs) {
      return !(lhs == rhs);
    }
    friend bool operator<(const IterMut &lhs, const IterMut &rhs) {
      return rhs - lhs > 0;
    }
    friend bool operator<=(const IterMut &lhs, const IterMut &rhs) {
      return !(rhs < lhs);
    }
    friend bool operator>(const IterMut &lhs, const IterMut &rhs) {
      return rhs < lhs;
    }
    friend bool operator>=(const IterMut &lhs, const IterMut &rhs) {
      return !(lhs < rhs);
    }
  };

  class Iter : private IterMut {
    friend sequence_impl;

    using isize = isize;

    using IterMut::ptr;

    IterMut to_mut() const { return ptr; }

    Iter(Node *ptr) : IterMut(ptr) {}

  public:
    using difference_type = isize;
    using value_type = T;
    using pointer = const T *;
    using reference = const T &;
    using iterator_category = std::random_access_iterator_tag;

    Iter() = default;
    Iter(IterMut it) : IterMut(it) {}

    using IterMut::is_end;
    using IterMut::is_initialized;

    const Seq &from() const { return to_mut().from(); }

    using IterMut::position;

    const T &operator*() const { return ptr->to_node()->value; }
    const T *operator->() const { return &ptr->to_node()->value; }
    const T &operator[](isize n) const { return *(*this + n); }
    Iter &operator++() { return *this += 1; }
    Iter operator++(int) {
      auto ret = *this;
      ++(*this);
      return ret;
    }
    Iter &operator--() { return *this -= 1; }
    Iter operator--(int) {
      auto ret = *this;
      --(*this);
      return ret;
    }
    Iter &operator+=(isize n) { return *this = *this + n; }
    Iter &operator-=(isize n) { return *this += -n; }

    friend Iter operator+(const Iter &it, isize n) {
      return it.from().nth_iterator(isize(it.position()) + n);
    }
    friend Iter operator+(isize n, const Iter &it) { return it + n; }
    friend Iter operator-(const Iter &it, isize n) { return it + -n; }
    friend isize operator-(const Iter &lhs, const Iter &rhs) {
      return isize(lhs.position()) - isize(rhs.position());
    }

    friend void swap(Iter &lhs, Iter &rhs) { std::swap(lhs, rhs); }

    friend bool operator==(const Iter &lhs, const Iter &rhs) {
      return lhs.ptr == rhs.ptr;
    }
    friend bool operator!=(const Iter &lhs, const Iter &rhs) {
      return !(lhs == rhs);
    }
    friend bool operator<(const Iter &lhs, const Iter &rhs) {
      return rhs - lhs > 0;
    }
    friend bool operator<=(const Iter &lhs, const Iter &rhs) {
      return !(rhs < lhs);
    }
    friend bool operator>(const Iter &lhs, const Iter &rhs) {
      return rhs < lhs;
    }
    friend bool operator>=(const Iter &lhs, const Iter &rhs) {
      return !(lhs < rhs);
    }
  };

  static void splay(NodeBase *ptr) {
    NodeBase *prev = nullptr;
    while (!ptr->is_end()) {
      NodeBase *next = ptr->parent;
      ptr->parent = prev;
      prev = ptr;
      ptr = next;
    }
    auto f = [](Node *p) {
      if (p->parent) {
        if (p->left().get() == p->parent) {
          return -1;
        } else {
          return 1;
        }
      } else {
        return 0;
      }
    };
    Seq *s = ptr->to_seq();
    SplayHelper<decltype(f)> h(std::move(s->root), std::move(f));
    h.splay();
    h.build_non_null();
    s->set_root(std::move(h.ptr));
  }

  static std::unique_ptr<Node> erase_help(IterMut first, IterMut last) {
    std::unique_ptr<Node> ret;
    if (first != last) {
      if (last.is_end()) {
        Seq *s = last.ptr->to_seq();
        Node *fn = first.ptr->to_node();
        splay(fn);
        ret = std::move(s->root);
        s->set_root(std::move(ret->left()));
      } else {
        Node *ln = last.ptr->to_node();
        splay(ln);
        Seq *s = ln->parent->to_seq();
        auto tree_last = std::move(s->root);
        s->set_root(std::move(tree_last->left()));
        Node *fn = first.ptr->to_node();
        splay(fn);
        ret = std::move(s->root);
        set_child<false>(tree_last.get(), std::move(ret->left()));
        s->set_root(std::move(tree_last));
      }
    }
    return std::move(ret);
  }

  friend IterMut erase(IterMut first, IterMut last) {
    erase_help(first, last);
    return last;
  }

  static usize size_(Node *ptr) {
    if (ptr) {
      return ptr->size;
    } else {
      return 0;
    }
  }

  static void reverse(Node *ptr) {
    if (ptr) {
      ptr->reverse();
    }
  }

  static void copy_tree(Node *ptr, SeqBuilder &b) {
    if (ptr) {
      if (ptr->reversed) {
        copy_tree(ptr->right().get(), b);
        b.add(ptr->value);
        copy_tree(ptr->left().get(), b);
      } else {
        copy_tree(ptr->left().get(), b);
        b.add(ptr->value);
        copy_tree(ptr->right().get(), b);
      }
    }
  }

  template <bool Side> static std::unique_ptr<Node> &child(Node *ptr) {
    return std::get<Side>(ptr->children);
  }

  template <bool Side>
  static void set_child(Node *ptr, std::unique_ptr<Node> &&ch) {
    if (ch) {
      ch->parent = ptr;
    }
    child<Side>(ptr) = std::move(ch);
  }

  static void print_tree(Node *ptr, usize depth = 0) {
    if (ptr) {
      print_tree(ptr->right().get(), depth + 1);
      std::cout << std::string(depth, ' ');
      std::cout << ptr->value << " " << ptr->reversed << "\n";
      print_tree(ptr->left().get(), depth + 1);
    }
  }
};

template <class T> using sequence = typename sequence_impl<T>::Seq;
