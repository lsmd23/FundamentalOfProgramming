#include <iostream>

template <typename T>
class Vector
{
public:
    // 默认构造函数，初始化一个空的Vector
    Vector() : _size(0), _capacity(1), _data(new T[1]) {}
    // 拷贝构造函数
    Vector(const Vector &other) : _size(other._size), _capacity(other._capacity), _data(new T[other._capacity])
    {
        std::copy(other._data, other._data + other._size, _data);
    }
    // 赋值运算符
    Vector &operator=(const Vector &other)
    {
        if (this != &other)
        {
            delete[] _data;
            _size = other._size;
            _capacity = other._capacity;
            _data = new T[other._capacity];
            std::copy(other._data, other._data + other._size, _data);
        }
        return *this;
    }
    // 析构函数，释放动态分配的内存
    ~Vector()
    {
        delete[] _data;
    }

    // 在Vector末尾添加一个元素
    void push_back(const T &value)
    {
        if (_size == _capacity)
        {
            _resize(_capacity * 2);
        }
        _data[_size++] = value;
    }

    // 重载[]操作符，提供非const版本，用于随机访问元素
    T &operator[](size_t index)
    {
        if (index >= _size)
        {
            throw std::out_of_range("Index out of range");
        }
        return _data[index];
    }

    // 重载[]操作符，提供const版本，用于随机访问元素
    const T &operator[](size_t index) const
    {
        if (index >= _size)
        {
            throw std::out_of_range("Index out of range");
        }
        return _data[index];
    }

    // 返回当前Vector的大小
    size_t size() const
    {
        return _size;
    }

    // 返回当前Vector的容量
    size_t capacity() const
    {
        return _capacity;
    }

    // 在指定位置插入一个元素
    void insert(size_t index, const T &value)
    {
        if (index > _size)
        {
            throw std::out_of_range("Index out of range");
        }
        if (_size == _capacity)
        {
            _resize(_capacity * 2);
        }
        for (size_t i = _size; i > index; --i)
        {
            _data[i] = _data[i - 1];
        }
        _data[index] = value;
        ++_size;
    }

    // 删除指定位置的元素
    void erase(size_t index)
    {
        if (index >= _size)
        {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = index; i < _size - 1; ++i)
        {
            _data[i] = _data[i + 1];
        }
        --_size;
    }

    // 判断Vector是否为空
    bool isEmpty() const
    {
        return _size == 0;
    }
    // 清空Vector中的所有元素
    void clear()
    {
        _size = 0;
    }

    // 排序函数，使用插入排序进行排序，结果是一个升序序列
    void sort()
    {
        for (size_t i = 1; i < _size; ++i)
        {
            T key = _data[i];
            size_t j = i;
            while (j > 0 && _data[j - 1] > key)
            {
                _data[j] = _data[j - 1];
                --j;
            }
            _data[j] = key;
        }
    }

    // 排序函数，使用插入排序对指定区间进行排序，结果是一个升序序列
    void sort(size_t start, size_t end)
    {
        if (start >= end || end > _size)
        {
            throw std::out_of_range("Invalid range");
        }
        for (size_t i = start + 1; i < end; ++i)
        {
            T key = _data[i];
            size_t j = i;
            while (j > start && _data[j - 1] > key)
            {
                _data[j] = _data[j - 1];
                --j;
            }
            _data[j] = key;
        }
    }

private:
    // 调整Vector的容量大小
    void _resize(size_t new_capacity)
    {
        T *new_data = new T[new_capacity];
        std::copy(_data, _data + _size, new_data);
        delete[] _data;
        _data = new_data;
        _capacity = new_capacity;
    }

    size_t _size;     // 当前Vector的大小
    size_t _capacity; // 当前Vector的容量
    T *_data;         // 存储元素的动态数组
public:
    friend class DNA;
};

struct Hole
{
    int danger;
    int kind;
    // 0=无
    // -1=陷阱
    // 1=防具
    Hole() : danger(0), kind(0) {}
    Hole(int _danger) : danger(_danger), kind(0) {}
};

struct Sum
{
    int sum;
    int HPleft;
    Sum() : sum(0), HPleft(0) {}
    Sum(int _sum, int _HPleft) : sum(_sum), HPleft(_HPleft) {}
};

int main()
{
    Vector<Vector<Hole>> map;

    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        Vector<Hole> temp;
        for (int j = 0; j < m; j++)
        {
            int danger;
            std::cin >> danger;
            temp.push_back(Hole(danger));
        }
        map.push_back(temp);
    }

    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        std::cin >> x >> y;
        map[x - 1][y - 1].kind = -1;
    }

    int p;
    std::cin >> p;
    for (int i = 0; i < p; i++)
    {
        int x, y;
        std::cin >> x >> y;
        map[x - 1][y - 1].kind = 1;
    }

    Vector<Vector<Sum>> dp;
    for (int i = 0; i < n; i++)
    {
        Vector<Sum> temp;
        for (int j = 0; j < m; j++)
        {
            temp.push_back(Sum());
        }
        dp.push_back(temp);
    }

    dp[0][0].HPleft = 0;
    dp[0][0].sum = map[0][0].danger;
    for (int i = 1; i < n; i++)
    {
        dp[i][0].HPleft = dp[i - 1][0].HPleft + map[i][0].kind;
        if (dp[i][0].HPleft < 0)
        {
            dp[i][0].sum = 200000000;     // 无穷大
            dp[i][0].HPleft = -100000000; // 无穷小
        }
        else
            dp[i][0].sum = dp[i - 1][0].sum + map[i][0].danger;
    } // 0列

    for (int i = 1; i < m; i++)
    {
        dp[0][i].HPleft = dp[0][i - 1].HPleft + map[0][i].kind;
        if (dp[0][i].HPleft < 0)
        {
            dp[0][i].sum = 200000000;     // 无穷大
            dp[0][i].HPleft = -100000000; // 无穷小
        }
        else
            dp[0][i].sum = dp[0][i - 1].sum + map[0][i].danger;
    } // 0行

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << dp[i][j].sum << " ";
        }
        std::cout << std::endl;
    }
    // 输出dp数组

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (dp[i - 1][j].HPleft + map[i][j].kind < 0 && dp[i][j - 1].HPleft + map[i][j].kind < 0)
            {
                dp[i][j].sum = 200000000;
                dp[i][j].HPleft = -100000000;
            }
            else if (dp[i - 1][j].HPleft + map[i][j].kind < 0) // 上面的HP小于0
            {
                dp[i][j].sum = dp[i][j - 1].sum + map[i][j].danger;
                dp[i][j].HPleft = dp[i][j - 1].HPleft + map[i][j].kind;
            }
            else if (dp[i][j - 1].HPleft + map[i][j].kind < 0) // 左边的HP小于0
            {
                dp[i][j].sum = dp[i - 1][j].sum + map[i][j].danger;
                dp[i][j].HPleft = dp[i - 1][j].HPleft + map[i][j].kind;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        std::cout << dp[i][j].sum << " ";
                    }
                    std::cout << std::endl;
                }
                // 输出dp数组
            }
            else
            {
                if (dp[i - 1][j].sum < dp[i][j - 1].sum)
                {
                    dp[i][j].sum = dp[i - 1][j].sum + map[i][j].danger;
                    dp[i][j].HPleft = dp[i - 1][j].HPleft + map[i][j].kind;
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < m; j++)
                        {
                            std::cout << dp[i][j].sum << " ";
                        }
                        std::cout << std::endl;
                    }
                    // 输出dp数组
                }
                else
                {
                    dp[i][j].sum = dp[i][j - 1].sum + map[i][j].danger;
                    dp[i][j].HPleft = dp[i][j - 1].HPleft + map[i][j].kind;
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < m; j++)
                        {
                            std::cout << dp[i][j].sum << " ";
                        }
                        std::cout << std::endl;
                    }
                    // 输出dp数组
                }
            }
        }
    } // 其他

    if (dp[n - 1][m - 1].sum >= 200000000)
        std::cout << "failed" << std::endl;
    else
        std::cout << dp[n - 1][m - 1].sum << std::endl;

    return 0;
}

/*
3 3
1 2 4
1 3 9
4 7 4
3
2 2
3 1
2 3
1
1 2
*/