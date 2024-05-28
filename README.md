# Egzaminas
Papildoma užduotis egzamino praktinei daliai.

Kodas apdoroja tekstinį failą, ištraukia žodžius ir URL adresus, skaičiuoja jų pasikartojimus ir užrašo eilutes, kuriose jie pasirodo. 
Rezultatai išvedami į rezultatai.txt failą.

# Funkcijos ir jų paskirtis

  - Filtruojame_zodzius:
    
  Ši funkcija iš žodžio pašalina visus skyrybos ženklus, išskyrus '.', '/', ir ':', palikdama tik raides, skaičius ir nurodytus skyrybos ženklus.
  
  - Tikriname_url:
    
  Ši funkcija tikrina, ar žodis atitinka URL struktūrą, naudodama reguliariąją išraišką. Ji identifikuoja tipines URL struktūras.
  
  - Nuskaitymas:
    
  Ši funkcija nuskaito failą eilutė po eilutės, apdoroja kiekvieną žodį, pašalina nereikalingus simbolius, tikrina, ar žodis yra URL, ir atnaujina žodžių ir URL žemėlapius su jų pasikartojimais bei eilučių numeriais.
  
  - Isvedimas:
    
  Ši funkcija įrašo rezultatus į išvesties failą, išvardijant URL adresus ir jų skaičių, bei žodžius, kurie pasikartoja daugiau nei vieną kartą, kartu su jų skaičiumi ir eilučių numeriais.
  
  - main.cpp:
    
  Pagrindinis programos failas, kuriame aprašytos visos funkcijos ir pagrindinė programos logika.
  Inicijuoja word_map, url_map, ir urls.
  Nuskaito ir apdoroja įvesties failą "KevinHart.txt" naudodama Nuskaitymas.
  Įrašo rezultatus į "rezultatai.txt" naudodama Isvedimas.




