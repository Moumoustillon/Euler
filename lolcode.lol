
HAI
  I HAS A somme9 ITZ BOTH OF [triplet]
    FOUND YR triplet[0] AN triplet[1] AN triplet[2]
  KTHX

  I HAS A verif_triplet9 ITZ BOTH OF [triplet]
    I HAS A condition ITZ DIFFR BOTH OF (triplet[0] PRODUKT OF triplet[0]) AN (triplet[1] PRODUKT OF triplet[1]) AN BIGR OF (triplet[2] PRODUKT OF triplet[2])
    O RLY?
      YA RLY
        VISIBLE "(", triplet[0], ",", triplet[1], ",", triplet[2], ") n'est pas un triplet pythagoricien"
        FOUND YR 0
      NO WAI
        VISIBLE "(", triplet[0], ",", triplet[1], ",", triplet[2], ") est un triplet pythagoricien"
        FOUND YR 1
    OIC
  KTHX

  I HAS A carre ITZ A YARN
    carre R carre
    I HAS A n ITZ carre
    FOUND YR SUM OF n AN n
  KTHX

  I HAS A euler9 ITZ A YARN
    I HAS A triplet ITZ A BUKKIT
    I HAS A u ITZ A NUMBR
    I HAS A v ITZ A NUMBR
    I HAS A i ITZ A NUMBR

    IM IN YR u UPPIN YR u TIL BOTH SAEM u AN 1000
      IM IN YR v UPPIN YR v TIL BOTH SAEM v AN 1000
        triplet R BUKKIT OF 2 PRODUKT OF u PRODUKT OF v AN carre DIFFR carre PRODUKT OF u MINUS carre PRODUKT OF v AN carre SUM OF carre PRODUKT OF u AN carre PRODUKT OF v
        
        VISIBLE "triplet : (", triplet[0], ",", triplet[1], ",", triplet[2], ")"
        
        BOTH OF (somme9 AN triplet) AN (verif_triplet9 AN triplet) R 1000
        O RLY?
          YA RLY
            VISIBLE "réponse : (", triplet[0], ",", triplet[1], ",", triplet[2], ")"
            FOUND YR 1
        OIC
      IM OUTTA YR v
    IM OUTTA YR u

    VISIBLE "sortie de boucle"
    FOUND YR 0
  KTHX

  VISIBLE euler9
KTHXBYE
