# Rapport

## Calcul du nombre théorique de permutations possibles

Le puzzle est composé de **9 pièces uniques**, chacune pouvant être placée dans n'importe quel ordre.  
Le nombre total de permutations sans tenir compte des rotations est donné par : 
```9! = 362880```

Chaque pièce peut être rotée dans **4 orientations** différentes, ce qui ajoute un facteur multiplicatif supplémentaire :  

```(9! * 4⁹) = 95 126 814 720```  

Soit environ **95 milliards** de configurations possibles.

## Comparaison avec le nombre d’appels récursifs réalisés

Notre algorithme fonctionne en **brute force**, testant chaque pièce avec ses **4 rotations possibles**.  
Si une pièce n'est pas compatible avec la précédente, nous passons à la suivante.

### Résultats observés :
| Solution trouvée     | Nombre de rotations | Nombre de récursions |
|----------------------|--------------------|----------------------|
| 1c 9a 6b 2a 4b 8b 7a 3a 5a  | 4'028  | 251  |
| 1b 5d 4a 7a 6a 2a 8a 3a 9d  | 5'607  | 348  |
| 4b 2b 9a 5a 6b 3b 1c 7b 8b  | 30'492 | 1'746  |
| 5c 3c 7c 8d 4d 2c 6d 9c 1a  | 35'329 | 2'018  |
| 6c 8c 5b 9b 4c 3b 1d 2b 7b  | 45'583 | 2'583  |
| 7d 2d 1b 3d 4a 9d 5d 8a 6a  | 50'137 | 2'847  |
| 8d 7d 1a 3d 6d 5c 9c 2d 4d  | 58'324 | 3'310  |
| 9b 3c 8c 2c 6c 7c 4c 5b 1d  | 64'775 | 3'669  |




On constate que, bien que le nombre de permutations théoriques soit **immense (95 milliards)**, notre algorithme trouve des solutions en effectuant **quelques dizaines de milliers de rotations**.

## Comparaison avec l'affirmation commerciale de Djeco

La marque Djeco décrit son puzzle comme ayant **"des millions de possibilités et une seule solution"**.  
D'un point de vue purement mathématique, notre calcul montre que le nombre réel de configurations possibles est bien plus élevé que "des millions" (**95 milliards**).

Cependant, dans la pratique, l'exploration des configurations n'est pas exhaustive et se limite aux **configurations valides**.  
Ainsi, bien que le chiffre avancé par Djeco soit sous-estimé, leur message marketing reste pertinent car il met en avant la rareté de la solution unique.
