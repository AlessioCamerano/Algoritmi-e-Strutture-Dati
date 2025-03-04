# Relazione sui Tempi di Risposta dell'Algoritmo di Prim
## Introduzione
Questo esperimento analizza l'efficienza dell'algoritmo di Prim per il calcolo della Foresta di Copertura Minima (Minimum Spanning Forest, MSF) su grafi non orientati e pesati. La soluzione utilizza una struttura dati basata su heap per la gestione delle priorità degli archi, consentendo di determinare iterativamente l'arco di peso minimo. I test sono stati condotti sul dataset italian_dist_graph.csv, con l'obiettivo di valutare i tempi medi di esecuzione dell'algoritmo.

## Metodologia
Le funzioni principali dell'algoritmo sono implementate secondo i seguenti prototipi:

### Classe Prim
```java
public static <V, L extends Number & Comparable<L>> 
Collection<? extends AbstractEdge<V, L>> minimumSpanningForest(Graph<V, L> graph);
public static double TotalWeight(LinkedList<AbstractEdge<String, Double>> minimumForest);
```
### Classe PriorityQueue
```java
public PriorityQueue(Comparator<E> comparator);
public boolean empty();
public boolean push(E e);
public boolean contains(E e);
public E top();
public void pop();
public boolean remove(E e);
```
Le funzioni di Prim gestiscono il calcolo della Foresta di Copertura Minima e il calcolo del peso totale della stessa. La classe PriorityQueue implementa una coda di priorità basata su heap, fondamentale per selezionare gli archi con peso minimo durante l'elaborazione.

## Risultati
L'Algoritmo crea la MSF del file .csv in qualche secondo

## Analisi dei Risultati

L'algoritmo ha completato il calcolo della MSF in qualche secondo per un grafo di circa 56000 records. I risultati sono coerenti con la complessità teorica dell'algoritmo di Prim.

L'insieme degli archi selezionati ha soddisfatto i requisiti di una Foresta di Copertura Minima: i nodi del grafo risultano collegati senza cicli, e il peso complessivo della foresta è minimo.

La PriorityQueue implementata ha gestito in modo efficace l'ordinamento degli archi, garantendo che l'algoritmo lavorasse con i pesi minimi ad ogni iterazione.

## Conclusioni
L'implementazione dell'algoritmo di Prim ha dimostrato di essere efficace per calcolare la MSF su grafi di dimensioni considerevoli, completando l'elaborazione in un tempo medio di qualche secondo. La combinazione di una struttura dati robusta e una corretta gestione dei nodi e degli archi assicura prestazioni affidabili.
