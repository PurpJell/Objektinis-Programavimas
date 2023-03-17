Versija 0.1
Dvi programos versijos, viena su dinaminiais masyvais, kita su vektoriais
Programos leidžia įvesti norimą skaičių studentų ir jiems įvesti norimą skaičių pažymių bei apskaičiuoti pažymių vidurkį ir medianą ir juos išvesti.


Versija 0.2
Išplėstas programos versijos su vektoriais funkcionalumas, dabar galima pasirinkti, kad duomenys būtų irašyti iš failo ir yra išvedami surikiuoti abecėlės tvarka pagal vardą į failą res.txt

Versija 0.3
Į programą įtrauktas išimčių valdymas (kai nerandamas failas, įvedami ne tokie duomenys, neteisingai paruoštas failas) bei programos funkcijos aprašytos faile funk_v03.cpp ir sukurti antraščių failas op.h ir Makefile

Versija 0.4
Galima generuoti studentų failą pasirenkant, kiek įrašų generuoti (1k, 10k, 100k, 1M, 10M). Generuojant failą naudojamas quick sort algoritmas vietoj bubble sort. Skaičiuojamas visos programos ir atskirų jos dalių vykdymo laikas.

Vykdymo laikas su skirtingais įrašų kiekiais:
(Failo generavimas, rūšiavimas, studentų skirstymas, studentų išvedimas, visas laikas)
1k: 1s, 0s, 0s, 0s, 3s.
10k: 1s, 0s, 0s, 0s, 2s.
100k: 2s, 0s, 0s, 0s, 4s.
1M: 5s, 1s, 0s, 0s, 9s.
10M: 41s, 38s, 2s, 4s, 95s.
