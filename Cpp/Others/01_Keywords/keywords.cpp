// 编译命令：g++ keywords.cpp -o keywords -std=c++11 -pthread
#include <iostream>
#include <typeinfo>
#include <thread>
#include <assert.h>
#include <map>

/*
 *  alignas (C++11)
 *  alignof (C++11)
 *  and
 *  and_eq
 *  asm
 *  auto
 *  bitand
 *  bitor
 *  bool
 *  break
 *  case
 *  catch
 *  char
 *  char16_t (C++11)
 *  char32_t (C++11)
 *  class
 *  compl
 *  concept (概念TS)
 *  const
 *  constexpr (C++11)
 *  const_cast
 *  continue 
 *  decltype (C++11)
 *  default
 *  delete
 *  do
 *  double
 *  dynamic_cast
 *  else
 *  enum
 *  explicit
 *  export
 *  extern
 *  false
 *  float
 *  for
 *  friend
 *  goto
 *  if
 *  inline
 *  int
 *  long
 *  mutable
 *  namespace
 *  new
 *  noexcept (C++11)
 *  not
 *  not_eq
 *  nullptr (C++)
 *  operator
 *  or
 *  or_eq
 *  private
 *  protected
 *  public
 *  register
 *  reinterpret_cast
 *  requires (概念TS)
 *  reutrn
 *  short
 *  signed
 *  sizeof
 *  static
 *  static_assert (C++11)
 *  static_cast
 *  struct
 *  switch
 *  template
 *  this
 *  thread_local (C++11)
 *  throw
 *  true
 *  try
 *  typedef
 *  typeid
 *  typename
 *  union
 *  unsigned
 *  using
 *  virtual
 *  void
 *  volatile
 *  wchar_t
 *  while
 *  xor
 *  xor_eq
 *  
 * */

//==================================================
// 关键词：alignas      功能：设置内存对齐（参数为2的幂次方）
// 关键词：alignof      功能：查看内存对齐。
//--------------------------------------------------
struct alignas(8) S {};
struct alignas(1) U { S s; }; // 无效：U包含S，故应至少对齐为8
struct Foo { int i; float f; char c; };
struct Empty {};
struct alignas(64) Empty64 {};
// struct alignas(0) BB {}; // 出错：参数应为2的幂次方。
struct alignas(1) Double { double d; };
struct Obj { char a; int b; };

// sizeof(Obj) == 8     内存大小：a占一个字节，但与b间隔3个字节。
// alignaof(Obj) == 4   内存对齐：以最大值b为准。

void alinInfo() {
    std::cout << "Alignment of" "\n"
        "- char:                " << alignof(char)      << "\n" // 1
        "- pointer:             " << alignof(int*)      << "\n" // 8 4
        "- class Foo:           " << alignof(Foo)       << "\n" // 4
        "- empty class:         " << alignof(Empty)     << "\n" // 1
        "- alignas(64) Empty:   " << alignof(Empty64)   << "\n" // 64
        "- alignas(1) Double:   " << alignof(Double)    << "\n" // 8
    << std::endl;
}
//==================================================

//==================================================
// 关键词：and      功能：and 等价于 && 。
// 关键词：and_eq   功能：and_eq 等价于 &= 。
//--------------------------------------------------
void showAnd() {
    int a = 3;
    int b = 4;
    if ((a == 3) && (b == 4)) {
        // do something
    }

    if ((a == 3) and (b == 4)) {
        // do something
    }

    b and_eq a;
    b &= a;
    b = b & a;
}
//==================================================

//==================================================
// 关键词：asm      功能：引入汇编语句。
//--------------------------------------------------
void showAsm() {
    asm ("movq $60, %rax\n\t"
        "movq $2, %rdi\n\t"
        "syscall");
    // exit(2);
}   
//==================================================

//==================================================
// 关键词：auto      功能：自动类型推导。
//--------------------------------------------------
float add(int a, float b) {
    return a+b;
}

// double get_fun(int a) {
//     return (double)a;
// }

void showAuto() {
    // int aa = 1 + 2;
    auto a = 1 + 2;
    std::cout << "type of a: " << typeid(a).name() << "\n"; // int
    float bb = add(1, 1.2);
    auto b = add(1, 1.2); 
    std::cout << "type of b: " << typeid(b).name() << "\n"; // float
    auto c = (1, 2);
    std::cout << "type of c: " << typeid(c).name() << "\n"; // int

    auto my_lambda = [](int x) { return x + 3; };
    std::cout << "my_lambda: " << my_lambda(5) << "\n";  

    // auto my_fun = get_fun(2);
    // std::cout << "type of my_fun: " << typeid(my_fun).name() << "\n";
    // std::cout << "my_fun: " << my_fun(3) << "\n"; 
}   
//==================================================

//==================================================
// 关键词：bitand      功能：位与，相当于 & 。
// 关键词：bitor      功能：位或，相当于 | 。
//--------------------------------------------------
void showBitAndOr() {
    auto a = 3L;
    auto b = 4;
    auto c = a bitand b;    // &
    auto d = a bitor b;     // |
    std::cout << "type of c: " << typeid(c).name() << "\n"; 
    std::cout << "type of d: " << typeid(d).name() << "\n";  
}   
//==================================================

//==================================================
// 关键词：bool      功能：布尔类型 。
//--------------------------------------------------
void showBool() {
    auto a = true;
    auto b = false;
    *(reinterpret_cast<char*>(&a)) = -1;
    std::cout << a << "  " << b << std::endl;
    if (a == true) {
        std::cout << "i'm true\n";
    } else if (a == false) {
        std::cout << "i'm false\n";
    } else {
        std::cout << "what?\n";
    }
}   
//==================================================

//==================================================
// 关键词：break      功能： 跳出当前loop。
//--------------------------------------------------
void showBreak() {
    int a = 10;
    for(;;) {
        for(;;) {
            ++a;
            if (a > 1000) break;
        }
        if (a > 100000) break;
    }
}   
//==================================================

//==================================================
// 关键词：case      功能： 搭配 switch选择结构。
// 关键词：catch     功能： 异常try-catch-throw结构。
// 关键词：char      功能： 字符。
//        Windows：signed char, -128 ~ +127
//        Linux：  unsigned char, 0 ~ 255 
// 关键词：char16_t
// 关键词：char32_t
// 关键词：class     功能： 类。
// 关键词：compl     功能： 等价于~。
// 关键词：concept   功能： 解决模板出错提示模糊问题。
// 关键词：const     功能： 不可变。
//==================================================

//==================================================
// 关键词：constexpr 功能： 根据已知条件在编译期间获取值。
//--------------------------------------------------
int fact(int n) {
    return n <= 1 ? 1:(n * fact(n - 1));
}

constexpr int factorial(int n) {
    return n <= 1 ? 1:(n * factorial(n - 1));
}

template<int N>
struct NN {
    void print() { std::cout << N << std::endl; }
}; 

void showConstexpr() {
    auto a = fact(4);
    auto b = factorial(4);
    char group[factorial(6)]; // 可以定义 factorial(6) 使用长度
    NN<factorial(8)> nn;
    nn.print();
}   
//==================================================

//==================================================
// 关键词：const_cast   功能： 改变const不可变性。
//--------------------------------------------------
void testA(volatile const int& a) {}
void testB(volatile const int& b) {}

void showConstCast() {
    const volatile int j = 3; // volatile限定，禁止编译器优化。
    std::cout << j << std::endl; 
    std::thread aa([&j] { testA(j); });
    std::thread bb([&j] { testB(j); });
    // std::cout << j << std::endl;
    int* pj = const_cast<int*>(&j);
    *pj = 4;
    std::cout << j << std::endl; // 未加volatile时编译器自动优化：j被替换为3。

}   
//==================================================

//==================================================
// 关键词：continue   功能：跳过本次循环剩余部分开始下次循环。
//--------------------------------------------------
void showContinue() {
    int a = 10;
    for(;;) {
        for(;;) {
            ++a;
            if (a > 1000) continue;
        }
        if (a > 100000) continue;
    }
}   
//==================================================

//==================================================
// 关键词：decltype   功能：获取 表达式\变量 类型。
//--------------------------------------------------
struct S_decltype { double x; };
void showDecltype() {
    const S_decltype* a = new S_decltype{ 0 };
    auto aa = a->x;
    decltype(a->x) y;           // double
    auto& cc = y;
    decltype((a->x)) z = y;     // double& ，括号=>引用
}

template<typename T, typename U>
auto add(T a, U b) -> decltype(a+b) {
    return a + b;
}
//==================================================

//==================================================
// 关键词：default        功能： 搭配 switch选择结构。
// 关键词：deletw         功能： 
// 关键词：do             功能： 
// 关键词：double         功能： 
// 关键词：
//==================================================

//==================================================
// 关键词：dynamic_cast   功能：类层次间的上行转换和下行转换。
//--------------------------------------------------
struct Base{ virtual ~Base(){} };

struct Derived : Base {
    virtual void name() {}
};

void showDynamicCast() {
    Base *b1 = new Base;
    // （指针类型）转换失败：不会抛出异常
    if (Derived *d = dynamic_cast<Derived *>(b1)) {
        std::cout << "downcast from b1 to d successful\n";
        d->name();
    }

    Base *b2 = new Derived;
    if (Derived *d = dynamic_cast<Derived *>(b2)) {
        std::cout << "downcast from b2 to d successful\n";
        d->name();
    }
    // （引用类型）转换失败：抛出异常
    // Base bb;
    // Derived& cc = dynamic_cast<Derived&>(bb);
}
//==================================================

//==================================================
// 关键词：else   功能：配合if使用。
//==================================================

//==================================================
// 关键词：enum         功能：枚举，大小不固定。
// 关键词：enum class   功能：提供命名空间，可指定大小。 
//--------------------------------------------------
enum Color { red, green, blue };

// 为enum class元素指定大小，默认为int(32位4个字节) 
enum class NewColor : char { Red, Green = 20, Blue };

void showEnum() {
    Color r = red;
    switch (r)
    {
    case red:
        std::cout << "i'm red\n";
        break;
    case green:
        std::cout << "i'm green\n";
        break;
    case blue:
        std::cout << "i'm blue\n";
        break;
    default:
        std::cout << "what?\n";
    }
    int a = r;  // enum 直接赋值

    NewColor R = NewColor::Green;
    switch (R)
    {
    case NewColor::Red:
        std::cout << "i'm Red\n";
        break;
    case NewColor::Green:
        std::cout << "i'm Green\n";
        break;
    case NewColor::Blue:
        std::cout << "i'm Blue\n";
        break;
    default:
        std::cout << "what?\n";
    }
    int b = static_cast<int>(R); // enum class 需要 static_cast 转换
}
// // bool 类型的参数使用 enum class 代替
// enum class IsGood { Yes, No };

// void show(IsGood);

// void test() {
//     show(IsGood::Yes); 
// }
//==================================================

//==================================================
// 关键词：explicit 功能：防止类构造函数(1个参数)的隐式自动转换.。
//--------------------------------------------------
struct A
{
    A(int) {}
    A(int, int) {}
    operator int() const { return 0; } // 将 A 作为 int 型
};

struct B
{
    explicit B(int) {}
    explicit B(int, int) {}
    explicit operator int() const { return 0; } // 将 B 作为 int 型
};

void handleA(A a) {}
void handleB(B b) {}

void showExplicit() {
    A a1 = 1; // A a1 = A(1);
    // B b1 = 1; // 错误,explicit不允许隐式类型转换。
    A a2(2);
    B b2(2);
    A a3 = (4, 5); // A a3 = {4, 5};
    // B b3 = (4, 5); // 错误,explicit不允许隐式类型转换。
    int na1 = a1;
    // int nb1 = b2; // 错误,explicit不允许隐式类型转换。 
    int na2 = static_cast<int>(a1);
    int nb2 = static_cast<int>(b2);
    A a4 = (A)1;
    B b4 = (B)1; // 正确,显式类型转换

    handleA(a1);
    handleA(1);
    handleB(b2);
    // handleB(1); // 错误,explicit不允许隐式类型转换。
}
//==================================================

//==================================================
// 关键词：export   功能：模板在cpp中实现，而非头文件；未实现，已丢弃。
// 关键词：extern
// 关键词：false
// 关键词：float
// 关键词：for
//==================================================

//==================================================
// 关键词：friend   功能：修饰友元函数和友元类，单向、不继承。
//--------------------------------------------------
class Y {
    int data;
    friend std::ostream &operator<<(std::ostream &out, const Y &o);
    template <typename T> friend class F;
    template <typename T> friend void f(T) {};
};

class YY : public Y {};

void showFriend() {}
//==================================================

//==================================================
// 关键词：goto   功能：跳转语句，易出错。
//--------------------------------------------------

void showGoto() {
    auto i = 0;
    std::cout << "halo\n";
label:
    for (; i < 10; i++)
    {
        if (i == 3) {
            ++i;
            goto label;
        }
        if (i == 8) 
            goto endloop;
    }
endloop:
    std::cout << "bye\n";
}
//==================================================

//==================================================
// 关键词：inline   功能：空间换时间(代码展开)，仅是对编译期的建议。
//--------------------------------------------------
inline int add(int a, int b) {
    return a + b;
}

class In {
    public:
        // 类中实现函数：默认为inline
        void print() const { std::cout << "halo\n"; }
        int value() const { return m_value; }
    private:
        int m_value;
};

void showInline() {}
//==================================================

//==================================================
// 关键词：int   
// 关键词：long     
// 关键词：mutable      功能：修饰的变量在const函数中可变(突破const限制)。
// 关键词：namespace    功能：命名空间，避免命名冲突。
// 关键词：new
//==================================================

//==================================================
// 关键词：noexcept   功能：修饰函数提示编译器该函数不会抛出异常(进行优化)。
//--------------------------------------------------
void fun() noexcept {
    std::cout << "halo" <<std::endl;
    // 使用前应确保函数一定无异常，否则将执行abort();
}

void showNoexcept() { fun(); }
//==================================================

//==================================================
// 关键词：not          功能：相当于!
// 关键词：not_eq       功能：相当于!=     
//==================================================

//==================================================
// 关键词：nullptr   功能：空指针
//--------------------------------------------------
template<typename T, typename U>
void func(T t, U u) { t(u); }

void nullPointer(int* a) {
    std::cout << "i'm a pointer\n" << std::endl;
}

void showNullptr() { 
    nullPointer(0);
    nullPointer(NULL);
    nullPointer(nullptr);
    func(nullPointer, nullptr);
    func(nullPointer, (int*)0); // 模板中0将被推导为int类型，而非int*类型，需要强转类型。
    func(nullPointer, (int*)NULL); // 同上
}
//==================================================

//==================================================
// 关键词：operator   功能：运算符重载
// 常用需要重载的运算符：= == < <= > >= !=
//--------------------------------------------------
struct C {
    C() : m_value(new int()) {}
    C(const C& rhs) : m_value(new int(*(rhs.m_value))) {}
    ~C() { delete m_value; }
    C& operator = (const C& rhs) { *m_value = *(rhs.m_value); }
    int operator & () { return 10; }
    private:
        int* m_value;
};

void showOperator() { 
    C a;
    C b = a; // 拷贝构造
    auto address = &a;
    std::cout << address << std::endl;

    // string 实现了=、+=运算符重载
    std::string str1("abc");
    std::string str2("def");
    str1 += str2;
    auto str3 = str1 + str2;
    std::cout << str1 << std::endl;
    std::cout << str3 << std::endl;
}
//==================================================

//==================================================
// 关键词：or          功能：相当于|
// 关键词：or_eq       功能：相当于|=    
// 关键词：private     功能：面向对象权限修饰符
// 关键词：protected   功能：面向对象权限修饰符   
// 关键词：public      功能：面向对象权限修饰符
// 关键词：register    功能：建议将修饰的变量存入寄存器(提升效率)，已弃用
//==================================================

//==================================================
// 关键词：reinterpret_cast   功能：
//        reinterpret_cast  无关类型间转换。
//        static_cast       非多态类型间转换，无安全检查。
//        const_cast        常量指针或引用转换为非常量指针或引用（仍指向原来对象）
//        dynamic_cast      类层次间转换（目标类型是类的指针、引用或void*，原类型是指针或引用）
//        c like cast       C风格cast。
//--------------------------------------------------
void showReinterpretCast() { 
    auto a = 1;
    auto p = reinterpret_cast<char*>(&a);
    if (p[0] == 1)
        std::cout << "the system is little endian" << std::endl;
    else
        std::cout << "the system is big endian" << std::endl;
    auto pp = (char*)(&a);
    const C c;
    auto pbb = const_cast<C*>(&c);
    auto cbb = (C*)(&c);
    int d = 100;
    auto dd = static_cast<char>(d);
    auto ddd = (char)d;
}
//==================================================

//==================================================
// 关键词：require   功能：
// 关键词：return    功能：    
// 关键词：short     功能：短整型，2字节。
// 关键词：signed    功能：有符号。   
//==================================================

//==================================================
// 关键词：sizeof   功能：内存大小。
//--------------------------------------------------
struct S_Empty {};
struct S_Base1 { int a; };
struct S_Base2 { static int a; };   // 内部static仅是声明，非定义，故sizeof(S_Base2)为1
int S_Base2::a = 1;
struct S_Derived : S_Base1 { int b; };
struct S_Bit { unsigned bit : 1; };

void showSizeof() { 
    S_Empty e;
    S_Derived d;
    S_Base1& b = d;
    S_Bit bit;
    std::cout << sizeof(S_Empty) << std::endl; // 1
    std::cout << sizeof(S_Base1) << std::endl; // 4
    std::cout << sizeof(S_Base2) << std::endl; // 1
    std::cout << sizeof(&e) << std::endl; // 8(64位)
    std::cout << sizeof(S_Derived) << std::endl; // 8(64位)
    // std::cout << sizeof(void) << std::endl; // 警告：void为无效类型。
    // std::cout << sizeof(int[]) << std::endl; // 出错：非完整类型。
    // std::cout << sizeof(bit.bit) << std::endl; // 出错：sizeof()的操作数不能为位域。
}
//==================================================

//==================================================
// 关键词：static   功能：静态。
//--------------------------------------------------
static int globalA = 0; // 静态全局变量：编译时分配。

void printInfo() {
    static int localStatic = 0; // 更改局部变量存活期
    ++localStatic;
    std::cout << globalA << " " << localStatic << std::endl;
}

void showStatic() { 
    int i;
    for (i = 0; i < 10; i++)
        printInfo();
}
//==================================================

//==================================================
// 关键词：static_assert   功能：编译期断言(要求断言动作必须在编译时完成)，assert为运行时断言。
//--------------------------------------------------
template<typename T>
void S_func(T t) {
    static_assert(alignof(T) == 4, "only for alignof 4");
}

void showStaticAssert() { 
    assert((sizeof(int) == 4) && "only work for int for 32 bit");
    static_assert(sizeof(long) == sizeof(long long), "only work for long == long long");

    int i;
    S_func(i);
}
//==================================================

//==================================================
// 关键词：static_cast  功能：类型转换。
// 关键词：struct       功能：结构体。    
// 关键词：switch       功能：选择结构。
// 关键词：template     功能：模板。  
// 关键词：this         功能：指向当前对象。
// 关键词：thread_local 功能：多线程。
// 关键词：throw        功能：异常try-catch-throw结构。
// 关键词：true         功能：bool值。
// 关键词：try          功能：异常try-catch-throw结构。
//==================================================

//==================================================
// 关键词：typedef   功能：别名，非宏替换，强于 #define（定义指针时）。
//--------------------------------------------------
typedef unsigned long ulong;
class Comp {
    typedef std::map<int, ulong> Group;
    Group a;
    void aa() {
        // std::map<int, unsigned long>::iterator iter = a.find(10);
        // Group::iterator iter = a.find(10);
        auto iter = a.find(10);
    }
};

void showTypedef() {}
//==================================================

//==================================================
// 关键词：typeid       功能：类id。
// 关键词：typename     功能：类name。    
// 关键词：union        功能：联合体。
// 关键词：unsigned     功能：无符号。  
// 关键词：using        功能：配合namespace声明命名空间。
// 关键词：virtual      功能：定义虚函数与虚基类。
// 关键词：void         功能：。
// 关键词：volatile     功能：禁止编译器优化。
// 关键词：wchar_t      功能：双字节类型（宽字符类型）。
// 关键词：while        功能：while循环。
// 关键词：xor          功能：相当于 ^ ，异或（相同为0，不同为1）。
// 关键词：xor_eq       功能：^=。
//==================================================

int main()
{
    // alinInfo();
    // showAnd();
    // showAsm();
    // showAuto();
    // showBitAndOr();
    // showBool(); // linux gcc 下为 true
    // showBreak();
    // showConstexpr();
    // showConstCast();
    // showContinue();
    // showDecltype();
    // showDynamicCast();
    // showEnum();
    // showExplicit();
    // showFriend();
    // showGoto();
    // showInline();
    // showNoexcept();
    // showNullptr();
    // showOperator();
    // showReinterpretCast();
    // showSizeof();
    // showStatic();
    // showStaticAssert();
    // showTypedef();

    return 0;
}