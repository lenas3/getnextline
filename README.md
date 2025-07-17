Static Variables

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
