Static Variables

Satatic anahtar kelimesi kullanıldığı yere göre iki farklı anlam kazanır. Eğer bir blok içerisinde değişken tanımlarken kullanılmışsa
bu **"kalıcılık"** anlamına gelir. Blok dışına çıkıldığında değişkenler erişilemez hale gelir ancak  değişken değerleri yok olmaz.
static anahtar kelimesi eğer bir fonksiyon ya da global değişken* tanımlamasında kullanıılyorsa bu **"gizlilik"** anlamına gelir. Yani, bu 
fonksiyon ya da değişken başka dosyalara tamamen yabancı olacaktır. Sadece tanımlandığı dosya içerisinde tanınırlar ve başka bir kaynak 
dosyasından çağrılamaz hale gelirler.

      int fonk_1 (…)
      {  fonk_1’in gövdesi  }
      static double z;
      static int fonk_2 (…)
      {  fonk_2’in gövdesi  }
      int main (…)
      {  main’in gövdesi  }

  
Yukarıdaki örnekte bu dosya içerisinde olunduğu müddetçe z ve fonk_2'ye ulaşılabilir. Ancak başka kaynak dosyalarından fonksiyonlar ulaşamaz.

_*Global Değişken : Bir programda tüm fonksiyonlar ve bloklar tarafından erişilebilen değişkenlerdir._
    _C dilinde fonksiyonların dışında, genellikle dosyanın en üstünde tanımlanır. Tanımladığı dosya veya modül boyunca geçerlidir._
    _Bazı kodlama dillerinde global değişken değerini değiştrimek için özel bir söz dizimi gerekebiliyor,_
    _ama C dilinde buna gerek yoktur. Tüm fonksiyonlar global değişkenler tarafından doğrudan erişilip değeri değiştirilebilir._
