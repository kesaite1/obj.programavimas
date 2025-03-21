***Objektinio programavimo projektas***

Ši programa skirta darbui su studentų duomenimis, padeda uos valdyti, talpinti ir apdoroti. 

**Funkcijos**
1. Studentų duomenų įvedimas: vardas, pavardė, namų darbų bei egzamino pažymiai.
2. Galimas duomenų įvedimas keturiai skirtingais būdais:
   2.1 Vartotojas įveda visus duomenis
   2.2 Vartotojas įveda vardą ir pavardę, pažymiai yra generuojami
   2.3 Visi studento duomenys yra generuojami
   2.4 Studentų duomenys yra skaitomi iš failo
   2.5 Studentų duomenys skaitomi iš sugeneruoto failo
3. Pasirenkami rūšiavimo parametrai
4. Pasirenkas išvedimo būdas
5. Galutinio pažymio skaičiavimas aritmetinio vidurkio ir medianos būdu

**Klaidų aptikimas**

Kode panaudotas išimčių valdymas (angl. Exception Handling), naudojamas try-catch mechanizmas.



**Duomenys išvedimo failuose yra struktūruoti tokiu būdu:**

|Vardas         |Pavardė        |Galutinis (vid.)  |Galutinis (med.)  |
|---------------|---------------|------------------|------------------|
|VardasNR1      |PavardėNR1     |7.35              |7.76              |
|VardasNR2      |PavardėNR2     |9.28              |9.28              |
|...........    |...........    |......            |........          |


**Programos testavimo procesas ir rezultatai**

Kiekviena programa yra ištestuojama atskirai, o rezultatai surašomi į bendrą testo laikų failą *laikas.txt* gautų rezultatų palyginimui. 
Testavimo metu yra testuojamos šios programos operacijos:
1. duomenų nuskaitymas iš failų į atitinkamą konteinerį,
2. studentų rūšiavimas didėjimo tvarka konteineryje (funkcija sort),
3. studentų skirstymas  į dvi grupes/kategorijas (naujų konteinerių su skirtingais studentais kūrimas).

Gautų testavimo rezultatų su 100000 įrašų failu pvz.:

 ------------------------------------------------------------------------------------------
Programos su vector konteineriais laikai:
 
Duomenu skaitymo is failo laikas: 12.0054
Studentu rusiavimo pasirinkta tvarka laikas: 1.89215
Studentu skirstymo i dvi grupes laikas: 0.626981

Testu laiku vidurkis: 2.9049
------------------------------------------------------------------------------------------
Programos su list konteineriais laikai:

Duomenu skaitymo is failo laikas: 22.3816
Studentu rusiavimo pasirinkta tvarka laikas: 0.134302
Studentu skirstymo i dvi grupes laikas: 1.08133
Testu laiku vidurkis: 4.71944
------------------------------------------------------------------------------------------
Programos su deque konteineriais laikai:

Duomenu skaitymo is failo laikas: 28.3951
Studentu rusiavimo pasirinkta tvarka laikas: 3.66368
Studentu skirstymo i dvi grupes laikas: 1.91435

Testu laiku vidurkis: 6.79462
------------------------------------------------------------------------------------------

Taip pat kiekvienos programos veikimo metu yra sugeneruojamas failas su CPU, RAM ir disko apkrovos duomenimis programos testavimo metu.
Rezultatų pvz.:
Vector konteineris:
CPU usage: LoadPercentage  18              
RAM usage: RAM naudojimas: 95%
Disk usage:
FreeSpace    Name  Size          
27100065792  C:    254761791488  

List konteineris:
CPU usage: LoadPercentage  13              
RAM usage: RAM naudojimas: 93%
Disk usage:
FreeSpace    Name  Size          
27226103808  C:    254761791488  

Deque konteineris:
CPU usage: LoadPercentage  28   
RAM usage: RAM naudojimas: 92%
Disk usage:
FreeSpace    Name  Size          
27336642560  C:    254761791488  

Testavimo išvados:
Remiantis programos operacijų laikais, efektyviausiai veikianti programa naudoja vector konteinerius, o mažiausiai efektyvi programa naudoja deque konteinerius. 



![Duomenų įvedimo procesas](https://github.com/user-attachments/assets/26189234-f898-48fd-a30b-62bf3c1a61e5)
![Studentų duomenų išvedimas](https://github.com/user-attachments/assets/86870dbd-6b5f-4b90-9b4e-786b5260a189)
![Testavimo rezultatų pavyzdys](https://github.com/user-attachments/assets/c30d1664-350b-4ed5-8aec-4a21663a4afe)



main