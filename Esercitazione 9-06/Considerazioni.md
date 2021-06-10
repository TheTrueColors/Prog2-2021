# Liste e Alberi per ogetti Veicolo
## 09/06/2021

## Analisi del problema

Il testo richiede la progettazione e l'implementazione di una o più opportune strutture dati astratte (ADT) che consentano di:

+ inserire elementi nella strutture dati appropriate al loro tipo di veicolo;
+ cercare elementi nella struttura dati;
+ cancellare elementi nella struttura dati sotto una cilindrata minima.
+ stampare gli elementi seguendo una vista PostOrder
+ stampare gli elementi seguendo una vista PreOrder
+ stampare gli elementi seguendo una vista InOrder
+ cercare il massimo nella struttura dati
+ cercare il minimo nella struttura dati
+ cercare il successore di un elemento
+ cercare il predecessore di un elemento


Tra i requisiti, si nota che:

+ la ricerca e la cancellazione avvengono in base a dei valori passati come parametri alle rispettive funzioni;
+ i dati da inserire sono forniti in  file di testo;
+ la stampa della struttura dati Tree deve essere effettuata seguendo una vista tra: inorder, postorder, preorder.

## Considerazioni progettuali

1. La struttura di un Binary Search Tree suggerisce l'utilizzo di una struttura dati che sia "percorribile" in entrambi i versi;
2. Il fatto che la struttura dati venga popolata a partire da un file di testo suggerisce che è opportuno utilizzare un'implementazione dinamica, che consenta quindi di variare il numero di elementi nella struttura stessa;
3. L'inserimento viene effettuato seguendo le propietà dell'ordinamento parziale della struttura, poiche i nodi vanno inseriti a sinistra se la cilindrata della key del nodo da inserire è più piccola della cilindrata della key del nodo in cui siamo arrivati o a destra se più grande, cioè ogni nodo avra a sinistra i figli con la cilindrata più piccola e a destra i figli con la cilindrata più grande;
4. Gli elementi da inserire sono dei veicoli di tipo diverso perciò opto a creare una classe che verrà ereditata, contente i membri marca e cilindrata, dalle classi figlie auto, moto e barca;
5. Il fatto che l'inserimento e il travaso delle varie strutture dati sono indipendenti tra di loro ho deciso di utilizzare la programmazione multi-thread per alleggerire la complessità computazionale e svolgere queste operazioni in parallelo cosi da velocizzare l'esecuzione del programma.

Si decide, pertanto, di utilizzare una **Lista** per ogni veicolo adattata all'esigenze della struttura dati, con un puntatore alla root; e dove gli elementi che la compongono hanno 3 puntatori per i BST che conterrano i veicoli travasati e una lista per ogni veicolo per contenere i dati iniziali.


## Classi utilizzate

+ **Node**: classe template che rappresenta un nodo dell BST(Tree) con figlio sinistro(left) , figlio destro(right) e genitore(parent).
     - Qui vengono implementate le funzioni base di: creazione del figlio, settare figlio destro , figlio sinistro e parent, e restituire i puntatori a left, right e parent oltre all'overload del cout(operator<<) per poter effettuare la stampa dell'ogetto di tipo Node<T>.
+ **Tree**: classe template che rappresenta una lista adattata alla struttura dati di un Binary Search Tree, con un puntatore alla root dell'albero.
    - Qui vengnono implementate le funzioni richieste: le varie viste per la stampa, le funzioni di ricerca e le funzioni di inserimento e cancellazione.
+ **Auto, Moto, Barca**: classe che definisce l'ogetto come ogetto di tipo veicolo.
    - Qui mi occupo di inizializzare l'ogetto e di gestirne la stampa.
+ **ListAuto, ListMoto, ListBarca**: classi che rappresentano le liste dei veicoli.
    -Qui gestisco l'inserimento dei valori e la stampa della lista.
+ **Veicolo**: classe che si occupa di definire i membri delle classi che la deriveranno.
+ **Nodo**: classe che rappresenta un nodo della lista dei veicoli.
