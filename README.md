# Uzay-Similasyonu
Bu proje, Güneş sistemindeki 8 farklı gezegenin kütleçekim ivmelerini kullanarak çeşitli fiziksel deneylerin sonuçlarını simüle eden, C programlama dili ile geliştirilmiş akademik bir çalışmadır.

Proje Hakkında
Bu yazılım, kullanıcıdan alınan verileri (kütle, zaman, uzunluk vb.) gezegenlerin yerçekimi koşullarına göre işler. Projenin temel amacı, pointer (işaretçi) aritmetiği ve modüler programlama prensiplerini fiziksel problemler üzerinde uygulamaktır.

Temel Özellikler
8 Gezegen Desteği: Merkür, Venüs, Dünya, Mars, Jüpiter, Satürn, Uranüs ve Neptün verileri tanımlıdır
.9 Farklı Deney Modülü: Serbest düşmeden asansör deneyine, sarkaç periyodundan kaldırma kuvvetine kadar geniş yelpazede hesaplama.Gezegen Bilgi Merkezi: Gezegenler hakkında kısa ve öz bilgiler sunan interaktif modül.
Hata Yönetimi: Ternary operatörleri ile negatif değer kontrolü ve girdi doğrulama.
Pointer Aritmetiği: Veri erişiminde tamamen işaretçi mantığı (*(ptr + i)) kullanılmıştır.

Kullanılan Teknolojiler
Dil: C
Kütüphaneler: stdio.h, math.h (Matematiksel hesaplamalar için)

Simüle Edilen Deneyler ve Formüller
Program içerisinde aşağıdaki fiziksel kanunlar modellenmiştir:
Serbest Düşme: $h = \frac{1}{2}gt^2$
Sarkaç Periyodu: $T = 2\pi\sqrt{\frac{L}{g}}$
Ağırlık Hesaplama: $F = m \cdot g$
Asansör Deneyi (Etkin Ağırlık): $N = m(g \pm a)$

Akademik Bilgi
Bu çalışma, Bursa Teknik Üniversitesi bünyesinde Öğr. Gör. Ergün GÜMÜŞ tarafından yürütülen Algoritmalar ve Programlama dersi dönemi projesi kapsamında hazırlanmıştır.Geliştiren: Ceren Ebrar Yücetombullar
Tarih: Ocak 2026
