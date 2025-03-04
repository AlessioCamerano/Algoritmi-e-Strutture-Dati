# Relazione sui Tempi di Risposta di due Implementazioni di Edit Distance
## Introduzione
In questo esercizio sono state valutate le prestazioni di due implementazioni dell'algoritmo di Edit Distance: una versione ricorsiva semplice e una versione ottimizzata tramite programmazione dinamica. Lo scopo era misurare l'efficienza e la capacità di completamento delle due implementazioni nell'analisi di un file di testo, confrontandole per tempo di esecuzione e comportamento.

## Metodologia
Le implementazioni testate sono le seguenti:

### Versione Ricorsiva: 
Una funzione che calcola la distanza di edit senza strutture di memoizzazione, risolvendo i sottoproblemi in modo indipendente.
### Versione Dinamica: 
Una funzione ottimizzata che utilizza una tabella di memoizzazione per memorizzare i risultati di sottoproblemi già risolti, riducendo i calcoli ridondanti.

Entrambe le implementazioni sono state integrate in un programma che legge un dizionario e un file di testo, confrontando ogni parola del testo con le parole del dizionario per determinare il miglior suggerimento basato sulla Edit Distance.

## Risultati

Implementazione	        Completamento	    Tempo Medio di Esecuzione

Versione Ricorsiva	    Non Termina	        N/D
Versione Dinamica	    Completa	        33 secondi

## Analisi dei Risultati

### Versione Ricorsiva

Problemi di Completamento: La versione ricorsiva non è riuscita a completare il test entro un tempo ragionevole. Questo risultato è dovuto alla crescita esponenziale delle chiamate ricorsive per problemi di dimensioni significative.
Limitazioni: La mancanza di memoizzazione implica che la funzione ricalcola continuamente gli stessi sottoproblemi, causando un drastico aumento del tempo di esecuzione. Per dataset di grandi dimensioni, la versione ricorsiva non è praticabile.

### Versione Dinamica

Prestazioni: La versione dinamica ha completato i test in un tempo medio di 33 secondi. Utilizzando una tabella di memoizzazione, ha ridotto significativamente il numero di calcoli ripetitivi rispetto alla versione ricorsiva.
Efficienza: Sebbene la versione dinamica richieda memoria aggiuntiva per la tabella di memoizzazione, l'ottimizzazione offerta rende l'algoritmo efficiente e adatto a dataset di grandi dimensioni.

## Confronto
Il confronto tra le due implementazioni evidenzia chiaramente i vantaggi della versione dinamica. Mentre la versione ricorsiva è inadeguata per dataset significativi a causa della sua complessità computazionale, la versione dinamica è stata in grado di gestire con successo il carico di lavoro in tempi accettabili.

## Conclusioni

La versione ricorsiva, pur essendo semplice da implementare, si è dimostrata impraticabile per problemi di dimensioni reali, non riuscendo a completare i test. La versione dinamica, invece, ha concluso l'elaborazione in un tempo medio di 33 secondi, dimostrando la superiorità della programmazione dinamica per scenari complessi.

Per applicazioni reali che coinvolgono grandi volumi di dati, la versione dinamica è chiaramente la scelta preferibile, sia per la sua efficienza che per la capacità di completare l'elaborazione in tempi ragionevoli.