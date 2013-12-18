PROI-LAB2
=========

Laboratorium PROI 2, semestr 13Z, EiTI. Klasa abstrakcyjna bufora. Prowadzący mgr inż. Mariusz Zubrzycki

Klasa abstrakcyjną bufor - zawiera zestaw funkcji do operowania na buforze.
Do tego dwie klasy dziedziczące po tej klasie:
BuforCykliczny - odpowiednik pierwszego projektu, ale z dynamicznym do alokowaną pamięcią przy wypełnieniu całego bufora.
BuforLista - klasa która przechowuje dane w liście

celem jest możliwość korzystania z klasy bufor bez względu czy kryje się pod nią obiekt klasy BuforCykliczny czy BuforLista .
W testach powinna być widoczna różnica w wydajności pomiędzy różnymi operacjami wykonywanymi na różnym typie buforu.

Wszystkie wymienione klasy mają być wzorcami aby umożliwić przechowywanie danych o dowolnym typie.

