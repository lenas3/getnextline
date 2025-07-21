Buffer: Veriyi geçici olarak depolamayı sağlayan veri alanı. 

**STATİC VARIABLES**

'static' anahtar kelimesi kullanıldığı yere göre iki farklı anlam kazanı:

1. Kalıcılık: Fonksiyon İçinde Statik Kullanımı

Eğer bir fonksiyon içerisinde değişken tanımlarken kullanılmışsa bu **"kalıcılık"** anlamına gelir. Blok dışına çıkıldığında değişkenler erişilemez hale gelir ancak değişken değerleri yok olmaz. Ayrıca fonksiyon her çağrıldığında eski değeri korunur. (Normalde fonksiyon içerisinde yerel değişkenler fonksiyon her çağrılıdğında yeniden oluşur, işlem bitince yok olur.)

2. Gizlilik: Fonksiyon Dışında Kullanım

static anahtar kelimesi fonksiyon prpotoipinde (daha önce ft_printf'te kullanmıştık) ya da fonksiyon dışında global değişkenin* tanımlamasında kullanıılyorsa bu **"gizlilik"**  anlamına gelir. Yani, bu fonksiyon ya da değişkenin erişilebilirliği o dosyayla kısıtlanır. Sadece tanımlandığı dosya içerisinde tanınırlar ve başka bir kaynak dosyasından çağrılamaz hale gelirler.

      int fonk_1 (…)
      {  fonk_1’in gövdesi  }
      static double z;
      static int fonk_2 (…)
      {  fonk_2’in gövdesi  }
      int main (…)
      {  main’in gövdesi  }

  
Yukarıdaki örnekte bu dosya içerisinde olunduğu müddetçe z ve fonk_2'ye ulaşılabilir. Ancak başka kaynak dosyalarından fonksiyonlar ulaşamaz.

_*Global Değişken : * Global değişken: Tüm fonksiyonlardan erişilebilen, fonksiyonların dışında tanımlanan değişkenlerdir. C dilinde global değişkenlere tüm fonksiyonlar doğrudan erişebilir ve değerlerini değiştirebilir. Diğer bazı dillerde bu işlem için özel sözdizimi gerekebilir, ancak C'de buna ihtiyaç yoktur._

----------------------------------------------------------------------------------------------------------------------------------------

**read FUNCTION** 

subject dosyasında izinli fonksiyonlardan biri de read fonksiyonu. read() fonksiyonu bir doysa veya girdiden raw byte okuuyan bir sistem çağrısıdır. fd (file descripotr) ile çalışır. 
                        
            fonksiyon prototipi: size_t read(int fd, void *buf, size_t count);
                                  fd: verinin okunacağı dosyaya ait file descriptor.
                                  buf: okunan verinin saklanacağı buffer
                                  count: buffer'a okunabilecek maksimum karakter sayısı.

return değerleri:
- okunan byte sayısı döner, bu byte sayısı count değişkeninden az olabilir.
- EOF'ye (end-of-file) erişilmişse 0 döner.
- herhangi bir hata durumunda -1 döner ve errno* global değişkenini ayarlar.
        _*errno: hata durumlarında hata kodunu tutan bir global değişkendir. her hatanın kendine ait bir errno değeri vardır ve errno değeri otomatik olarak ayarlanır._

read fonksiyonu satır farketmeksizin byte bazlı okuma yapar.


