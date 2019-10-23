<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta name="robots" content="noarchive"/>

<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />

<!--link rel="icon" type="image/gif" href="images/animated_favicon1.gif" -->

<title>Esercitazioni del corso di Laboratorio di Calcolo</title>
<link rel="stylesheet" type="text/css" href="style.css" media="screen" />

</head>
<body>
<div id="header">
	<div id="logo">
		<h1>Esercitazioni del <a href="http://www.phys.uniroma1.it/DipWeb/didattica/ccl/2012-13/ECTStriennale/LabCalco1213.pdf">Corso di Laboratorio di Calcolo</a></h1>
	</div>
	<!-- end #logo -->
	<div id="cssmenu">
          <ul>
            <li><a href="../../index.php">Torna alla pagina principale</a></li>
          </ul>
	</div>
	<!-- end #menu -->
</div>
<!-- end #header -->

<div id="page">
   <div id="content">
<a href="es11-lcsr01.c">es12-lcsr01.c</a>
<a href="es11-lcsr02.c">es12-lcsr02.c</a>
<a href="es11-lcsr03.c">es12-lcsr03.c</a>
<a href="es11-lcsr04.c">es12-lcsr04.c</a>
<a href="es11-lcsr05.c">es12-lcsr05.c</a>
<a href="es11-lcsr06.c">es12-lcsr06.c</a>
<a href="es11-lcsr07.c">es12-lcsr07.c</a>
<a href="es11-lcsr08.c">es12-lcsr08.c</a>
<a href="es11-lcsr09.c">es12-lcsr09.c</a>
<a href="es11-lcsr10.c">es12-lcsr10.c</a>
<a href="es11-lcsr11.c">es12-lcsr11.c</a>
<a href="es11-lcsr12.c">es12-lcsr12.c</a>
<a href="es11-lcsr13.c">es12-lcsr13.c</a>
<a href="es11-lcsr14.c">es12-lcsr14.c</a>
<a href="es11-lcsr15.c">es12-lcsr15.c</a>
<a href="es11-lcsr16.c">es12-lcsr16.c</a>
<a href="es11-lcsr17.c">es12-lcsr17.c</a>
<a href="es11-lcsr18.c">es12-lcsr18.c</a>
<a href="es11-lcsr19.c">es12-lcsr19.c</a>
<a href="es11-lcsr20.c">es12-lcsr20.c</a>
<a href="es11-lcsr22.c">es12-lcsr22.c</a>
<a href="es11-lcsr23.c">es12-lcsr23.c</a>
<a href="es11-lcsr24.c">es12-lcsr24.c</a>
<a href="es11-lcsr25.c">es12-lcsr25.c</a>
<a href="es11-lcsr26.c">es12-lcsr26.c</a>
<a href="es11-lcsr27.c">es12-lcsr27.c</a>
<a href="es11-lcsr28.c">es12-lcsr28.c</a>
<a href="es11-lcsr30.c">es12-lcsr30.c</a>
<a href="es11-lcsr31.c">es12-lcsr31.c</a>
<a href="es11-lcsr34.c">es12-lcsr34.c</a>
<a href="es11-lcsr35.c">es12-lcsr35.c</a>
<a href="es11-lcsr36.c">es12-lcsr36.c</a>
<a href="es11-lcsr37.c">es12-lcsr37.c</a>
<a href="es11-lcsr38.c">es12-lcsr38.c</a>
<a href="es11-lcsr39.c">es12-lcsr39.c</a>
<a href="es11-lcsr40.c">es12-lcsr40.c</a>
<a href="es11-lcsr42.c">es12-lcsr42.c</a>
<a href="es11-lcsr44.c">es12-lcsr44.c</a>
<a href="es11-lcsr45.c">es12-lcsr45.c</a>
<a href="es11-lcsr46.c">es12-lcsr46.c</a>
<a href="es11-lcsr48.c">es12-lcsr48.c</a>
<a href="es11-lcsr50.c">es12-lcsr50.c</a>

<pre>
lcsr 01:

-1: perche` packpietro viene aumentato con if prima ancora di avere davvero generato la bustina?
-1: 7 condizoni scritte a mano in while???
-3: la cella 0 dell’album non viene mai riempito causando il ciclo infinito
40 min di debug...

lcsr02: 30
-1: modificare l’iteratore di un ciclo for dentro il ciclo e` una brutta abitudine
perche` la funzione update si prende Nfig come argomento quando poi non ci fa nulla?
la logica di

lcsr03: 30
funziona Domanda e` inutile
funzione Packet ha argomenti inutili
-1: IntRand non genera mai il valore max tranne una sola volta.

lcsr04: 25
-3: il numero di figurine generate non viene mai restituito per essere usato
per aggiornare l'album
-2: update errato perche` aggiorna fino a FMAX anche quando la bustina ha meno figurine
-2: update riempie le figurine da 0 mentre check  e le altre funzioni cominciano sempre
dalla cella 1 ignorando 0!
+2: per parte corretta di exchange (figurina 0 mai considerata)

lcsr05: 30

lcsr06: 23
-1: perche` bustina e` lunga 221 ?
-3:  il numero di figurine generate non viene mai restituito per essere usato
-3: update e` errato in tutti i sensi

lcsr07: 27
-3: interfaccia di update errata. perche` prende entrambi gli album ?
update e` l’anti-funzione. passare due argomenti e due flag...
contadoppioni e` l’anti-funzione!
il programma funziona ma e` stato sconfitto lo scopo del programma.
tutte le vostre funzioni sono errate e rendono inutile il concetto della funzione

lcsr08: 23
-1: contadoppioni non dichiarata
-3: errore grave di logica. come fa un array lungo 6 elementi a contenere
le figurine da 0 a 7 (che sono 8!)
-2: vengono generate tra 4 e 6 figurine
-3: il ciclo per i doppioni nella bustina non ha senso
+4 scambi

lcsr09: senza voto

lcsr10: 29
-1: perche` funzione scelta prende double per restituire int ??
non ho capito la logica di exchange

lcsr11: 25
-3: il numero di figurine nella busta non e` mai restituito
-2: update assume ci sia sempre maxp figurine nella busta

lcsr12:  30
-1: tra scelta 0 ed 1 non ha senso duplicare tutto il codice quando la differenza e` 1 riga!

lcsr13: 30

lcsr14: 30
-1: modificare l’iteratore di un ciclo for dentro al ciclo e` cattiva programmazione

lcsr15: 29
-2: generatore numeri casuali non genera mai b!
-2: controllo1 e controllo2 vengono usati prima di essere inizializzati!

lcsr16:  30
non ho capito come pensavate di fare gli scambi. i e j non hanno senso

lcsr17: 27
-3: si producono N+1 figurine e non N. questo manda il programma in ciclo infinito e
il programma non puo` finire

lcsr18: 30
controllare la bustina dopo aver generato tutte le figure e` molto inefficiente

lcsr19: 25
-3: il numero di figurine nella busta non e` mai restituito
-2: update assume ci sia sempre Fnew figurine nella busta

lcsr20:
-3: non compila
-1: tra scelta 0 ed 1 non ha senso duplicare tutto il codice quando la differenza e` 1 riga!
-2: errore nella generazione numeri casuali
-2: si producono N+1 figurine e nn N
-3: manca controllo doppioni nella bustina
-3: non capisco la logica di check

lcsr22: 24
che senso hanno queste due righe?
      figpaolo++;
      figpaolo=check(paolo,Nf);
80 minuti per fare debug di questo programma che andava in ciclo infinito
-3: array non azzerati porta a situazioni imprevedibili
-3: errore nella generazione delle figurine nella bustina. l’ultima figurina (N-1)
mai generata e quindi non finisce mai il ciclo

lcsr23: 23
-2: srand(time(0))
tutti i numeri casuali sempre uguali
-3: ci sono doppioni nelle bustine
-2: le figurine vanno da 0 ad N (inclusi) mentre dovrebbero essere 0-N-1

lcsr24:
-2: le figurine vanno da 0 ad N (inclusi) mentre dovrebbero essere 0-N-1
lo scambio va fatto solo se nessuno dei due ha ancora finito

lcsr25: senza voto
-3: non compila

lcsr26:
abort ...
-3: errore nell’aggiornare l’album. non si usa la bustina ma l’album per errore
questo errore e considerando che ‘argomento passato e` un puntatore a un array errato
causa una sovrascritura di finepietro che porta all'abort
-3: in check() n viene usato senza essere azzerato se l’album e` pieno!
il valore n=1 viene ritornato in modo del tutto casuale ed imprevedibile
-2: manca srand48() e tutti i numeri estratti sono sempre gli stessi
-3: ciclo infinito perche` la generazione della bustina e` errata e nessun album si completa mai
40 min per fare debug di questo programma

lcsr27:
programma vuoto

lcsr30:
-3: non compila
ciclo infinito
-2: interfaccia packet non ha senso
si passa n che non viene usato
-3: il numero di figurine nella busta non e` mai restituito
-2: la condizione per fare lo scambio non tiene conto del fatto che possono aver gia` finito!
 -3: le figurine sono generate con indici che vanno da 1 a N, mentre gli array sono definite per
le figurine con indici da 0 a N-1

lcsr31:
-3: gravissimi errori di sintassi che rendono il programma del tutto errato
avete usato ovunque l’operatore = al posto di ==.
 -3: le figurine sono generate con indici che vanno da 1 a N, mentre gli array sono definite per
le figurine con indici da 0 a N-1
-3: errore grave di logica e di sintassi  while (pa[i]=pa[i--]);

-3: il numero di figurine nella busta non e` mai restituito
-2: aggiornamento dell’album non tiene conto del numero effettivo di figurine nella busta

lcsr34:
-1: non ha senso estrarre prima la bustina e poi fare IF per decidere se incrementare
una volta estratta la bustina la spesa deve auemnatre. perche` tutti questi if separati quando
devono essere un solo IF!
-3: errore nei doppioni nella busta. controlla solo che la nuova figurina nn sia uguale alla
precedente

lcsr35: 22
-3: tutti gli array ignorano la casella 0 e questo e` incompatibile con la lunghezza degli array
-3: i numeri generati sono sempre float mentre i numeri da usare erano sempre int
-2: controllo doppioni non ha senso
perche` in quel caso considerate anche la cella 0 ?

lcsr36:
-3: non compila
ma avete avuto una versione funzionante?
non capisco la logica e ci sono troppi errori

lcsr37:
ciclo infinito
-3: un po` ovunque vengono usate variabili non azzerate: b, c, comprate[]
-5: generazione numeri casuali errata e la bustina senza senso
la logica di check e di m e` davvero contorta

lcsr39: senza voto
-1: non mi dice i limiti del numero di figurine
come fa a capire chi sono le variabili con tutti i nomi di singola lettera??
gravemente incompleto

lcsr40:
scelta curiosa di nomi di variabili...
-1: tra scelta 0 ed 1 non ha senso duplicare tutto il codice quando la differenza e` 1 riga!
-2: errore di logica:  si generano x+1 figurine! e questo non e` compatibile con la lunghezza degli array
…
il programma non corrisponde a quanto richiesto

lcsr42:
-2: il numero di figurine generate non viene restituito mai e si assume il numero npax
giocando sul valore 0 della figurina

lcsr44:
-4: gravissimo errore di sintassi nell’uso di scanf()
come avete fatto a testare il programma?
-3: errore nella generazione numeri casuali
-3: non si controllano i doppioni
-3: la funzione update e` errata
-2: numero di figurine nella bustina non viene restituito e usato

lcsr45:
-1: perche` la scelta e` FLOAT??
ugualianza tra due float non deve essere mai usato tranne casi molto particolari, come lo 0

lcsr46:
ciclo infinito
-3: ciclo finisce quando uno dei due ha finito anche se l’altro album incompleto
-3: errore logico grave. non sono while ma if per singoli bambini. infatti va in  cilo infinito perche`
i controlli vengono fatti dopo ma non ci si arriva.
-2: errore generazione numero figurine nella busta
-3: condizione doppioni nella busta non ha senso
-2: il numero di figurine non viene restituito
-2: costopi e costopa usati ma non azzerati all'inizio
che ci fate con l’array doppioni?
-3: update cosa fa?

lcs48:
-3: errore nella generazione di numeri casuali

lcsr50:
-3: non compila
-2: il numero di figurine non viene restituito
-3: le figurine sono generate con indici che vanno da 1 a N, mentre gli array sono definite per
le figurine con indici da 0 a N-1
</pre>


   </div>
   <!-- end #content -->

   <div id="sidebar">
<div id="sidebar-bgtop"></div>

<div id="sidebar-content">
  <h3 class=h3sidebar>Last update: 31 Jan 2016</h3>

  <div class="sidemenu">
    <ul>
      <li><a href="../../material/esercitazione-12.pdf">testo</a></li>
      <li><a href="../../material/esercitazione-12.c">soluzione</a></li>
      <li><a href="../../voti/bonus.php">punti bonus</a></li>
    </ul>
  </div>


</div>

<div id="sidebar-bgbtm">
</div>
   </div>
   <!-- end #sidebar -->

</div>
<!-- end #page -->

<div id="footer">
<p>&copy; 2008. All Rights Reserved. Design by <a href="http://www.freecsstemplates.org/">Free CSS Templates</a>.</p>
</div>
<!-- end #footer -->


</body>
</html>
