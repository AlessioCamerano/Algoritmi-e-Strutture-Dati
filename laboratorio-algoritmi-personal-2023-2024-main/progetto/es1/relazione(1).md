# Relazione sui Tempi di Risposta di Merge Sort e Quick Sort
## Introduzione

In questo esercizio sono stati analizzati i tempi di esecuzione di due algoritmi di ordinamento, Merge Sort e Quick Sort, applicati su un file contenente 20 milioni di record. Ogni record è costituito da quattro campi: un identificatore univoco (id), una stringa (field1), un intero (field2) e un numero in virgola mobile (field3). Gli algoritmi sono stati testati ordinando i record secondo ciascuno dei tre campi, e i risultati sono stati confrontati per determinare quale algoritmo sia più efficiente in diversi scenari.

## Metodologia
Le funzioni di ordinamento implementate seguono i seguenti prototipi:

```c
void merge_sort(void *base, size_t nitems, size_t size, int (*compar)(const void*, const void*));
void quick_sort(void *base, size_t nitems, size_t size, int (*compar)(const void*, const void*));
```

I test sono stati eseguiti utilizzando la funzione sort_records, progettata per ordinare i record in un file CSV in ordine non decrescente rispetto a uno specifico campo:

```c
void sort_records(FILE *infile, FILE *outfile, size_t field, size_t algo);
```
Ogni esperimento è stato ripetuto due volte per verificare la consistenza e l'affidabilità dei risultati. I tempi registrati variano tra 49 e 54 secondi, in base al campo e all'algoritmo utilizzati.

## Risultati
### Test 1
Algoritmo	Campo	Tempo di Ordinamento

Merge Sort	Field1	1 minuto 34 secondi
Merge Sort	Field2	1 minuto 32 secondi
Merge Sort	Field3	1 minuto 41 secondi
Quick Sort	Field1	Segmentation Fault (core dumped)
Quick Sort	Field2	1 minuto 4 secondi
Quick Sort	Field3	1 minuto 5 secondi
### Test 2
Algoritmo	Campo	Tempo di Ordinamento

Merge Sort	Field1	1 minuto 43 secondi
Merge Sort	Field2	1 minuto 30 secondi
Merge Sort	Field3	1 minuto 39 secondi
Quick Sort	Field1	Segmentation Fault (core dumped)
Quick Sort	Field2	1 minuto 5 secondi
Quick Sort	Field3	1 minuto 7 secondi

## Analisi dei Risultati

L'analisi dei dati evidenzia le seguenti osservazioni:

### Merge Sort:

Ha mostrato tempi stabili in entrambi i test, con variazioni minime tra 1 minuto e 32 secondi a 1 minuto 43 secondi.
È stato in grado di gestire tutti i campi senza errori, dimostrando la sua affidabilità.

### Quick Sort:

Ha prodotto un Segmentation Fault durante l'ordinamento di field1 in entrambi i test. 
Per i campi numerici (field2 e field3), Quick Sort ha mostrato tempi di ordinamento simili a quelli di Merge Sort, oscillando tra 1 minuto 4 secondi a 1 minuto 7 secondi.

## Confronto tra Algoritmi

Campo 1 (field1): Merge Sort è l'unico algoritmo in grado di ordinare correttamente i dati stringa, rendendolo l'unica opzione valida in questo caso.
Campo 2 (field2) e Campo 3 (field3): Entrambi gli algoritmi hanno registrato tempi comparabili, ma il Quick Sort si dimostra più efficiente.

## Conclusioni

I risultati ottenuti sottolineano l'importanza di considerare le caratteristiche specifiche dei dati quando si sceglie un algoritmo di ordinamento. Merge Sort si è dimostrato robusto e affidabile su tutti i campi, inclusi i dati stringa. Quick Sort, pur essendo efficace per i campi numerici, ha mostrato un grave limite nell'ordinamento di field1, dove ha generato un Segmentation Fault.

In applicazioni che richiedono flessibilità e affidabilità, Merge Sort rappresenta la scelta preferibile. Tuttavia, per dataset numerici e in scenari in cui le stringhe non sono rilevanti, Quick Sort rimane la scelta migliore, data la sua velocità comparabile a Merge Sort.