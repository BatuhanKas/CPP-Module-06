
# CPP-Module-06

Bu projenin amaci size bütün casting tiplerini öğretmektir.

Toplamda 4 adet Casting Tipleri vardır. Bunlar asagidadir;

1- Static Cast <br>
2- Reinterpret Cast <br>
3- Dynamic Cast <br>
4- Const Cast <br>
**Ekstra:** uintptr_t veri tipi

## 1- Static Cast nedir?
***Static Cast:*** Tür dönüşümleri için kullanılır. Derleme zamanında dönüştürme işlemi yapar. Bir float'ı bir integer'a cast edebilirsiniz. ya da bir void*'ı bir integer* 'a. Çünkü void* aslında herhangi bir türden pointer'ı temsil eder. void*'ı static_cast ile istediğin türe dönüştürebilirsin. Çünkü bu dönüşüm mantıklı ve anlamlıdır. Ancak bir integer'ı bir string'e dönüştüremezsin, bir char*'a donusturemezsin, cunku anlamsizdir ve mantiksizdir. Ancak bir char'a donusturebilirsin. 
Bir integer*'i bir double*'a da donusturemezsin, çünkü artik isin icerisinde bellek adresleri ve pointerlar girmistir. Bu durumda reinterpret_cast kullanman gerekir.

Syntax'i aşağıdaki gibidir.

|`static_cast <type-id> ( expression )`|
|--------------------------------------|

-   **Bellek adresleri ve işaretçiler** ile çalışırken, işaretçileri farklı türler arasında dönüştürmeniz gerektiğinde **`reinterpret_cast`** kullanmanız gerekir.
- **Değerleri** (yani işaretçi olmayan basit türler) dönüştürürken ise **`static_cast`** kullanabilirsiniz. `static_cast`, **değerler** arasında anlamlı dönüşümler yapar. Örneğin, `float` gibi bir değeri `int` gibi başka bir değere dönüştürebiliriz çünkü bu dönüşüm anlamlıdır (ondalık kısmı kesilir).

```c++
float f = 3.14;
int x = static_cast<int>(f);
cout << x << endl;
```

Bu durumda `f` bir değerdir (adres değil, işaretçi değil) ve `static_cast` ile `float`'ı `int`'e dönüştürmek anlamlıdır.

- Void pointer, herhangi bir türdeki işaretçiyi temsil eder. `static_cast` ile `void*` işaretçisini belirli bir türe dönüştürebilirsin, ancak tür güvenliğine dikkat etmek gerekir.

```c++
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    void* voidPtr = &a;  // int* işaretçisini void* yapıyoruz
    
    // void*'i tekrar int*'e dönüştürüyoruz
    int* intPtr = static_cast<int*>(voidPtr);
    cout << "Değer: " << *intPtr << endl;

    return 0;
}
```
-   `void*` işaretçisi, bellekte herhangi bir türü temsil edebilir. `static_cast` ile bu işaretçiyi tekrar orijinal türü olan `int*` işaretçisine dönüştürdük.
-   Bu tür dönüşümler bellekte güvenli olmakla birlikte, yanlış türde bir işaretçiyi dönüştürmek tehlikeli olabilir.

Fakat bu istisna sadece void* icin geçerlidir. Diğer bütün işaretçiler ve bellek adresleri için `reinterpret_cast` kullanıyoruz.

## ***2- Reinterpret Cast nedir?***

***Reinterpret Cast:*** İşaretçiler arasında, yani bellekteki **adresleri** farklı türlerde yeniden yorumlamamız gerektiğinde, **`reinterpret_cast`** kullanmalıyız. Bu dönüşüm, bellekte işaret edilen verilere nasıl erişileceğini belirtir.

Syntax'i asagidaki gibidir;


|`reinterpret_cast < type-id > ( expression )`|
|---------------------------------------------|


#### Basit bir ornek;
```c++
int main() {
    float a = 3.14;
    float* f = &a;
    int* x = static_cast<int*>(f);  // Bu çalışmaz!
    std::cout << *x << std::endl;
}
```
Bu kodda, bir `float*` işaretçisini bir `int*` işaretçisine dönüştürmeye çalışıyoruz, ama bu tür bir işaretçi dönüşümü **`static_cast`** ile yapılamaz. Çünkü işaretçiler **bellekte** farklı veri türlerini gösterir ve bellekteki verilerin anlamı türlere göre değişir. İşte bu durumda **`reinterpret_cast`** kullanmamız gerekir;

```c++
int* x = reinterpret_cast<int*>(f);
```

### Neden Böyle?
-   **`static_cast`**, işaretçi olmayan veri türleri arasında **anlamlı dönüşümler** için kullanılır.
-   **`reinterpret_cast`**, işaretçiler ve bellek adresleri arasında **anlamsız ama geçerli** dönüşümler yapmak içindir (bellekteki veriyi farklı bir türde okumak gibi).

### Basitçe;
-   Değerler (`float` → `int`) için **`static_cast`** kullanılır.
-   İşaretçiler (`float*` → `int*`) için **`reinterpret_cast`** kullanılır çünkü adresler static_cast ile çevirilemez, reinterpret_cast ile dönüştürülebilir.

Eğer static_cast ile reinterpret_cast arasındaki farkı anlamakta zorlanıyorsanız, [link](https://stackoverflow.com/questions/6855686/what-is-the-difference-between-static-cast-and-reinterpret-cast)

## ***3- Dynamic Cast nedir?***

***Dynamic Cast:*** Tipler arası güvenli bir şekilde dönüştürme işlemi yapmaya yarayan bir operatördür. Genellikle, hiyerarşik bir sınıf yapısında yukarıdan aşağıya (base sınıftan türemiş sınıfa) veya aşağıdan yukarıya (türemiş sınıftan base sınıfa) yapılan tür dönüşümlerinde kullanılır.

Teorik olarak, `dynamic_cast`, **çalışma zamanında (RTTI)** tip kontrolü yapar. Bu, dönüştürmeye çalıştığınız nesnenin gerçekten **hedef sınıf tipine uygun olup olmadığını kontrol ettiği** anlamına gelir. Bu kontrolü yapabilmesi için, sınıf hiyerarşisinde en az bir sanal (virtual) fonksiyon bulunmalıdır. Aksi halde, `dynamic_cast` derleme zamanı hatasına neden olur.

1.  **Polimorfizm ve Sanal Fonksiyonlar**:
    -   `dynamic_cast` kullanılabilmesi için temel sınıfın (base class) polimorfik olması gerekir, yani en az bir sanal fonksiyon içermesi zorunludur.
    -   Polimorfizm, nesnelerin gerçek türünü çalışma zamanında belirlememizi sağlar ve C++'ta bu sanal fonksiyonlar sayesinde gerçekleştirilir.
2.  **Sanal Fonksiyonların Rolü**:
    -   Bir sınıfta sanal fonksiyon olduğunda, o sınıf için C++ bir "vtable" (sanal tablo) oluşturur. Bu tablo, sanal fonksiyonlara işaret eden bir yapıdır.
    -   `dynamic_cast`, bu vtable kullanarak bir nesnenin çalışma zamanındaki gerçek türünü kontrol eder. Eğer vtable yoksa, C++ bir nesnenin hangi türe ait olduğunu bilemez.
    -   Sanal fonksiyon olmadığı zaman, vtable de olmayacağı için `dynamic_cast` çalışmaz, çünkü tip bilgisi runtime (çalışma zamanı) sırasında izlenemez.

**Kısaca**, sanal fonksiyon zorunludur çünkü `dynamic_cast` işlemi, çalışma zamanında tür bilgisine ihtiyaç duyar. Bu bilgi, sanal fonksiyonlar sayesinde oluşturulan vtable ile izlenir.

---

![](https://media.geeksforgeeks.org/wp-content/uploads/20210506174912/one-300x131.png)

-   ****Downcasting:**** Bir temel sınıf işaretçisini (veya referansını) türetilmiş bir sınıf işaretçisine (veya referansına) dönüştürmeye downcasting denir. Şekil 1'de, Temel sınıf işaretçisinden/referansından "türetilmiş sınıf 1" işaretçisine/referansına downcasting yapmayı göstermektedir.

-  ****Upcasting:**** Türetilmiş bir sınıf işaretçisini (veya referansını) bir temel sınıf işaretçisine (veya referansına) dönüştürmeye upcasting denir. Şekil 1'de Türetilmiş sınıf 2 işaretçisinden/referansından "Temel sınıf" işaretçisine/referansına dönüştürme upcasting'i göstermektedir.

Daha detaylı bir anlatım için [notion](https://alike-dirigible-d37.notion.site/CPP-Notlarim-86e5660b50d740b5bd6b8803c8ae99f0?pvs=4) hesabıma bakabilirsin.

-   Daha çok, **temel sınıfı türetilmiş sınıfa** dönüştürürken (downcasting) kullanırız ve bunun güvenli olup olmadığını çalışma zamanı sırasında kontrol eder.
-   Eğer dönüşüm geçersizse, pointerlar için `nullptr`, referanslar için de `bad_cast` hatası döner.


**Pointer kismi icin basit bir ornek**:

```c++
#include <iostream>
using namespace std;

class  Base {  
public:
	virtual  ~Base(){};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

int main() {
	Base *ptr = new B;

	if (dynamic_cast<A *>(ptr))
		cout << "a success" << endl;
	else if (dynamic_cast<B *>(ptr))
		cout << "b success" << endl;
	else
		cout << "nullptr" << endl;
}
```

Bu kisimda if blogunun icerisinde downcasting islemi yapmaya calisiyorum. Bu sayede eger pointer'imin icerisindeki nesne benim downcasting yapmaya calistigim sinif ile uyumluysa, basarili bir sekilde downcasting yapiyor. Ancak uyumlu degilse **nullptr** donduruyor ve diger else if bloguna giriyor. Bu sayede bir pointerin icerisindeki nesnenin hangi siniftan olusturuldugunun kontrolunu yapabiliyorum.

**Referans kismi icin basit bir ornek**:

```c++
#include <iostream>
using namespace std;

class  Base {  
public:
	virtual  ~Base(){};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

int main() {
	Base *ptr = new B;

try {
	A &a = dynamic_cast<A &>(*ptr);
	(void)a;
	cout << "a success refere" << endl;
} catch (exception &e) {
		try {
			B &b = dynamic_cast<B &>(*ptr);
			(void)b;
			cout << "b success refere" << endl;
		} catch (exception &e) {
			cout << "exception fail " << endl;
		}
	}
}
```

**Dynamic Cast** eger referans bir nesneye downcast uygularken basarisiz olursa exception **std::bad_cast** firlatir.
Bu yuzden hatayi yakalayabilmek icin try catch bloklari arasinda kullanmamiz gerekiyor. İç içe try catch kullanarak bu sorunu çözebilirsiniz.

## ***4- Const Cast nedir?***

***Const Cast:*** - Bir nesnenin **const** veya **volatile** niteliklerini değiştiren tek C++ dönüştürme türüdür.

Temel amacı, bir nesneye **const** olarak erişimi geçici olarak kaldırmak ve nesne üzerinde değişiklik yapmaya olanak tanımaktır. Ancak, bu sadece derleme zamanındaki nitelikleri etkiler; nesnenin bellekteki **gerçek** const durumunu değiştirmez.

Syntax'i asagidaki gibidir;


|`const_cast <type-id> (expression)`|
|-----------------------------------|


**Const Pointerlarin, Const Olmayan Pointer'lara Dönüştürülmesi**: Bir `const` pointeri veya referansı, `const_cast` ile const olmayan bir pointera dönüştürebilirsin:
```c++
const int x =  10;
const int *a = &x;
int  *ptr =  const_cast<int*>(a);
cout << *ptr << endl;
```
Bu kisimda normal bir degiskenin onundeki const degerini kaldirip islem yaptik.

**Class icerisindeki bir degiskenin const degerini kaldirma**
```c++
class  Base {
private:
	const  int _x; 
	
public:
	Base(int x) : _x(x){};
	virtual  ~Base(){};
	void  setx(int x) { const_cast<int &>(_x) = x; };
	const  int  getx() { return _x; }
};

int main() {
	Base b1(10);
	cout << b1.getx() << endl;
	b1.setx(20);
	cout << b1.getx() << endl;
}
```
Bu kisimda ise private olan _x degiskeninin onundeki const degerini kaldirarak, setx fonksiyonu ile degerini degistirebiliyorum.

---

## ***Ekstra- uintptr_t veri tipi nedir?***

**`uintptr_t`**, C standardında tanımlanmış bir tamsayı veri tipidir. Bu veri tipi, bir işaretçiyi (`pointer`) bir tamsayıya dönüştürmek ve tam tersi işlemleri yapmak için kullanılır. `uintptr_t`, platformdan bağımsız olarak, **işaretçi büyüklüğüne eşit bir tamsayı türünü** garanti eder.

### `uintptr_t`'nin Özellikleri:

-   **Boyut**: `uintptr_t`, işaretçinin bellekteki adresini tutabilecek kadar geniş bir tamsayı türüdür. İşaretçi boyutuna eşittir, yani 32 bit bir sistemde 32 bitlik bir tamsayı, 64 bit bir sistemde ise 64 bitlik bir tamsayı olarak tanımlanır.
-   **İşaretsizdir**: `uintptr_t`, işaretsiz (`unsigned`) bir veri tipidir. Yani negatif değer almaz, sadece pozitif değerleri ve sıfırı temsil eder.
-   **İşaretçi - Tamsayı Dönüşümü**: İşaretçilerin tamsayılar üzerinde güvenli ve taşınabilir bir şekilde işlenmesi gerektiğinde kullanılır. Örneğin, işaretçi aritmetiği yaparken veya bellek adreslerini tamsayı olarak depolamak gerektiğinde kullanışlıdır.

### Nerede Kullanılır?

-   **İşaretçi ve tamsayılar arası dönüşüm**: Örneğin, bir işaretçiyi sayısal bir değer olarak saklayıp daha sonra tekrar işaretçiye çevirmek istediğinizde.
-   **Bellek yönetimi**: Düşük seviyeli bellek işlemleri yaparken, işaretçileri işaretçi aritmetiği yerine doğrudan tamsayılarla ifade etmek gerekebilir.

```c++
#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    int x = 42;
    int* ptr = &x;

    uintptr_t intPtr = reinterpret_cast<uintptr_t>(ptr);
    int* restoredPtr = reinterpret_cast<int*>(intPtr);

    cout << "Orijinal işaretçi: " << ptr << endl;
    cout << "uintptr_t değeri: " << intPtr << endl;
	cout << "Yeniden işaretçiye dönüştürülmüş: " << restoredPtr << endl;
}
```

---
## ***Arastirirken buldugum linkler;***

https://stackoverflow.com/questions/6855686/what-is-the-difference-between-static-cast-and-reinterpret-cast
https://en.cppreference.com/w/cpp/language/dynamic_cast
https://learn.microsoft.com/tr-tr/cpp/cpp/static-cast-operator?view=msvc-170
https://www.geeksforgeeks.org/const_cast-in-c-type-casting-operators/
https://www.geeksforgeeks.org/reinterpret_cast-in-c-type-casting-operators/
https://en.cppreference.com/w/cpp/types/integer
https://www.geeksforgeeks.org/dynamic-_cast-in-cpp/
https://stackoverflow.com/questions/1276847/difference-in-behavior-while-using-dynamic-cast-with-reference-and-pointers
https://stackoverflow.com/questions/3649278/how-can-i-get-the-class-name-from-a-c-object
https://www.digitalocean.com/community/tutorials/random-number-generator-c-plus-plus
https://stackoverflow.com/questions/1845482/what-is-the-uintptr-t-data-type
https://learn.microsoft.com/tr-tr/cpp/cpp/data-type-ranges?view=msvc-170
https://stackoverflow.com/questions/2684603/how-do-i-initialize-a-float-to-its-max-min-value
https://www.h-schmidt.net/FloatConverter/IEEE754.html
