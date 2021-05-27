# Binary Search Tree
## 27/05/2021

## Analisi del problema

Il testo richiede la progettazione e l'implementazione di una o più opportune strutture dati astratte (ADT) che consentano di:

+ inserire elementi nella struttura dati;
+ cercare elementi nella struttura dati;
+ cancellare elementi nella struttura dati.
+ stampare gli elementi seguendo una vista PostOrder
+ stampare gli elementi seguendo una vista PreOrder
+ stampare gli elementi seguendo una vista InOrder
+ cercare il massimo nella struttura dati
+ cercare il minimo nella struttura dati
+ cercare il successore di un elemento
+ cercare il predecessore di un elemento


Tra i requisiti, si nota che:

+ la ricerca e la cancellazione avvengono in base a dei valori passati come parametri alle rispettive funzioni;
+ i dati da inserire sono forniti in un file di testo(non implementato, utilizzo un inserimento manuale per fare dei test);
+ la stampa della struttura dati deve essere effettuata seguendo delle viste: inorder, postorder, preorder.

## Considerazioni progettuali

1. La struttura di un Binary Search Tree suggerisce l'utilizzo di una struttura dati che sia "percorribile" in entrambi i versi;
2. Il fatto che la struttura dati venga popolata a partire da un file di testo suggerisce che è opportuno utilizzare un'implementazione dinamica, che consenta quindi di variare il numero di elementi nella struttura stessa;
3. L'inserimento viene effettuato seguendo le propietà dell'ordinamento parziale della struttura, poiche i nodi vanno inseriti a sinistra se la key del nodo da inserire è più piccola della key del nodo in cui siamo arrivati o a destra se più grande, cioè ogni nodo avra a sinistra i figli con la key più piccola e a destra i figli con la key più grande;

Si decide, pertanto, di utilizzare una **Lista** adattata all'esigenze della struttura dati, con un puntatore alla root; e dove gli elementi che la compongono hanno 3 puntatori: 
+ al parent
+ al figlio sinistro
+ al figlio destro .

## Classi utilizzate

+ **Node<T>**: classe template che rappresenta un nodo della lista con figlio sinistro(left) , figlio destro(right) e genitore(parent).
     - Qui vengono implementate le funzioni base di: creazione del figlio, settare figlio destro , figlio sinistro e parent, e restituire i puntatori a left, right e parent oltre all'overload del cout(operator<<) per poter effettuare la stampa dell'ogetto di tipo Node<T>.
+ **BST<T>**: classe template che rappresenta una lista adattata alla struttura dati di un Binary Search Tree, con un puntatore alla root dell'albero.
    - Qui vengnono implementate le funzioni richieste: le varie viste per la stampa, le funzioni di ricerca e le funzioni di inserimento e cancellazione.

Trattandosi di un BST, le operazioni di inserimento, ricerca e cancellazione in generale avvengono in tempo **O(h)** dove h è l'altezza dell albero, e **O(n)** nel caso pessimo.
