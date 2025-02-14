Kırklareli Toplu Taşıma Hattı Planlaması
Bu proje, Kırklareli ilinin 3 farklı mahallesi için yeni bir toplu taşıma hattı tasarımı yapmayı amaçlamaktadır. Program, mahalleler için çeşitli kriterleri değerlendirerek en uygun güzergahı belirler ve maliyet-fayda analizini gerçekleştirir. Yazılım, Softmax algoritmasını kullanarak her kriterin ağırlığını hesaplar.

Amaç
Mahalle Seçimi: Nüfus yoğunluğu, mevcut ulaşım altyapısı, maliyet analizi, çevresel etki ve sosyal fayda gibi kriterlere göre en uygun toplu taşıma güzergahını belirlemek.
Softmax Kullanımı: Kriterlerin ağırlıklarını belirlemek ve her mahalle için bu kriterlere göre maliyet-fayda analizi yapmak.
Sonuçların Değerlendirilmesi: Program, her mahalle için maliyet-fayda oranını hesaplar ve en uygun güzergahı kullanıcıya bildirir.

Kullanılan Kriterler
Nüfus Yoğunluğu: Mahalledeki kişi başına düşen alan.
Mevcut Ulaşım Altyapısı: Mahalledeki toplu taşıma, yollar, vs. gibi mevcut altyapı.
Maliyet Analizi: Toplu taşıma hattının kurulması için gereken maliyet.
Çevresel Etki: Toplu taşımanın çevreye olan etkisi.
Sosyal Fayda: Toplu taşımanın mahalle halkına olan faydası.
Softmax Algoritması
Softmax algoritması, her bir kriterin ağırlığını hesaplamak için kullanılır. Girdi kriterlerinin pozitif ve normalleştirilmiş ağırlıklarını elde ederiz. Bu sayede her kriterin mahalleler üzerindeki etkisi daha doğru bir şekilde belirlenir.
