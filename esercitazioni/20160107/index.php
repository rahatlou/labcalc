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
<a href="es11-lcsr01.c">es11-lcsr01.c</a>
<a href="es11-lcsr02.c">es11-lcsr02.c</a>
<a href="es11-lcsr03.c">es11-lcsr03.c</a>
<a href="es11-lcsr04.c">es11-lcsr04.c</a>
<a href="es11-lcsr05.c">es11-lcsr05.c</a>
<a href="es11-lcsr06.c">es11-lcsr06.c</a>
<a href="es11-lcsr07.c">es11-lcsr07.c</a>
<a href="es11-lcsr08.c">es11-lcsr08.c</a>
<a href="es11-lcsr09.c">es11-lcsr09.c</a>
<a href="es11-lcsr10.c">es11-lcsr10.c</a>
<a href="es11-lcsr11.c">es11-lcsr11.c</a>
<a href="es11-lcsr12.c">es11-lcsr12.c</a>
<a href="es11-lcsr13.c">es11-lcsr13.c</a>
<a href="es11-lcsr14.c">es11-lcsr14.c</a>
<a href="es11-lcsr15.c">es11-lcsr15.c</a>
<a href="es11-lcsr16.c">es11-lcsr16.c</a>
<a href="es11-lcsr17.c">es11-lcsr17.c</a>
<a href="es11-lcsr18.c">es11-lcsr18.c</a>
<a href="es11-lcsr19.c">es11-lcsr19.c</a>
<a href="es11-lcsr20.c">es11-lcsr20.c</a>
<a href="es11-lcsr22.c">es11-lcsr22.c</a>
<a href="es11-lcsr23.c">es11-lcsr23.c</a>
<a href="es11-lcsr24.c">es11-lcsr24.c</a>
<a href="es11-lcsr25.c">es11-lcsr25.c</a>
<a href="es11-lcsr26.c">es11-lcsr26.c</a>
<a href="es11-lcsr27.c">es11-lcsr27.c</a>
<a href="es11-lcsr28.c">es11-lcsr28.c</a>
<a href="es11-lcsr30.c">es11-lcsr30.c</a>
<a href="es11-lcsr31.c">es11-lcsr31.c</a>
<a href="es11-lcsr34.c">es11-lcsr34.c</a>
<a href="es11-lcsr35.c">es11-lcsr35.c</a>
<a href="es11-lcsr36.c">es11-lcsr36.c</a>
<a href="es11-lcsr37.c">es11-lcsr37.c</a>
<a href="es11-lcsr38.c">es11-lcsr38.c</a>
<a href="es11-lcsr39.c">es11-lcsr39.c</a>
<a href="es11-lcsr40.c">es11-lcsr40.c</a>
<a href="es11-lcsr42.c">es11-lcsr42.c</a>
<a href="es11-lcsr44.c">es11-lcsr44.c</a>
<a href="es11-lcsr45.c">es11-lcsr45.c</a>
<a href="es11-lcsr46.c">es11-lcsr46.c</a>
<a href="es11-lcsr48.c">es11-lcsr48.c</a>
<a href="es11-lcsr50.c">es11-lcsr50.c</a>

<pre>

lcsr01

-1: media non prende la lunghezza di array come argomento
-1: errore di logica: i bordi appartengono a due mattonelle.
ad esempio y=0.5 appartiene sia ad A che a B. Vince A solo perche`
viene prima

lcsr02

-2: interfaccia errata di media. funzione void con uso di punttaore non serve
media doveva essere funzione double o float
i bordi non appartengono a nessuno e qualche granello si perde!
-2: il numero medio e` calcolato come int . invece il valore corretto e` ~0.7 e quindi ~1

lcsr03

-1: media non prende la lunghezza di array come argomento

lcsr04

-1: media non prende la lunghezza di array come argomento

lcsr05

-1: media non prende la lunghezza di array come argomento
-1: errore di logica: i bordi appartengono a due mattonelle.

lcsr06

-2: Funzione media calcola media di tutti 3 array e non uno a uno e non prende la lunghezza

lcsr07

-2: mancano le dichiarazioni delle funzioni
-1: media non prende la lunghezza di array come argomento
-1: errore di logica: i bordi appartengono a due mattonelle / mattonelle di grandezza diversa

lcsr08

-1: Funzione media non prende la lunghezza di array come argomento.
l’uso assurdo e senza senso dei puntatori.

lcsr09
-1: media non prende la lunghezza di array come argomento

-2: a che serve passare x ed y alla funzione genCirc? warning ignorato
-1: errore di logica: i bordi appartengono a due mattonelle / mattonelle di grandezza diversa

lcsr10:
-1: Funzione media non prende la lunghezza di array come argomento.

-2: Funzione contaPepe non d'accordo a quello richiesto
-3: Cerchio non correttamente generato

lcsr11
-2: la funzione media è ridondante, calcola tutte e tre le medie. non prende la lunghezza

-1: errore di logica: i bordi appartengono a due mattonelle / mattonelle di grandezza diversa
-1: interfaccia errata di contaPepe, non c'è alcun bisogno di passare i puntatori per x ed y

lcsr12

-1: Funzione media non prende la lunghezza di array come argomento.

lcsr13

-1: errore di logica: i bordi appartengono a due mattonelle / mattonelle di grandezza diversa
-3: errore grave: array usano indice i (del granello) anziche` j (esperimento)
-3: cicli invertiti

lcsr14

-1: Funzione media non prende la lunghezza di array come argomento.
-2: media non e' azzerata prima di essere usata

lcsr15

-1: media non prende la lunghezza di array come argomento, e neanche "azzera"
-1: interfaccia errata di contaPepe, non c'è alcun bisogno di passare i puntatori per x ed y
-1: uso errato/ridondante di contaPepe: le variabili a,b,c saranno sempre o 0 o 1
-1: errore di logica: i bordi appartengono a due mattonelle / mattonelle di grandezza diversa

lcsr16

-2: Funzione media calcola media di tutti 3 array e non uno a uno. non prende la lunghezza

lcsr17

-1: media non prende la lunghezza di array come argomento
-1: interfaccia errata di contaPepe, a che serve N?
-2: azzerati i contatori sbagliati

lcsr18

-1: Funzione media non prende la lunghezza di array come argomento.

lcsr19

-1: media non prende la lunghezza di array come argomento
-3: logica errata di genCirc, i punti generati non sono uniformi
-1: errore di logica: i bordi appartengono a due mattonelle / mattonelle di grandezza diversa

lcsr20

-1: Funzione media non prende la lunghezza di array come argomento.
-3: Granelli in un quadrato, non un cerchio
-1: errore di logica: i bordi appartengono a due mattonelle.
uso inutile di puntatori

lcsr22

-3: grani in un quadrato, non un cerchio
-2: R=1, non 0.77 come richiesto
-2: Funzione contaPepe non d'accordo a quello richiesto
-2: Funzione media calcola media di tutti 3 array e non uno a uno.
-1: La dichiarazione di la funzione media non coincide con la posteriore definizione

lcsr23

-1: media non prende la lunghezza di array come argomento
-5: interfaccia e logica errata di genCirc, i punti generati non appartengono a un cerchio
-1: errore di logica: i bordi appartengono a due mattonelle / mattonelle di grandezza diversa
-1: inutile uso dei puntatori X ed Y
-1: gli array di conteggio sono float invece di int

lcsr24

-1: Funzione media non prende la lunghezza di array come argomento.
-2: Funzione media calcola media di tutti 3 array e non uno a uno
-3: Errore di logica grave. Un solo loop (Nexp=100, N dato dal
   utente no viene mai usato). Nel array viene scritto il
   risultato di un unico granello (ma queste numero non viene
   mai azzerato, e quindi viene incrementato nel andare avanti
   dal loop)

lcsr25

-3: non compila
-2: la funzione media è ridondante, calcola tutte e tre le medie
-1: media non prende la lunghezza di array come argomento
-3: logica errata di genCirc, i punti generati non appartengono a un cerchio
-3: la funzione media non è implementata
-3: interfaccia errata di contaPepe
-2: errore grave: array di lunghezza pari a granelli
-2: uso di array con indice errato
-1: manca ciclo per numero di granelli
-2: manca il calcolo delle medie

lcsr26

-1: Funzione media non prende la lunghezza di array come argomento.
-2: Granelli solo nel primo quadrante del cerchio, non in tutto come richiesto
-3: Uso di "&array" anzi di "array", per pasare l'array a una funzione
   (warning ignorato) errore grave

lcsr27

-1: media non prende la lunghezza di array come argomento, e neanche "azzera"
-1: array inutili
-1: array di conteggio dichiarati come float invece che come int
-2: array di lunghezza errata
-5: interfaccia e logica errata di genCirc
-3: interfaccia e logica errata di contaPepe
-1: manca ciclo per numero di granelli

lcsr28

-6: tutte le funzioni mancanti
-3: granelli generati in un quadrato 0 - 0.77

lcsr30

-1: media non prende la lunghezza di array come argomento
-1: errore di logica: i bordi appartengono a due mattonelle.

lcsr31

-1: media non prende la lunghezza di array come argomento
-3:  errore di logica: interfaccia errata di contaPepe mi costringe a salvare tutti i granelli inutilmente
-2: interfaccia errata di media. perche` prendere &NC ??

lcsr34

-2: media non prende la lunghezza di array come argomento e funzione inutile
mettendo tutti i limiti incluso lo 0.77 nella funzione contaPepe la rende inutile

lcsr35

-2: uso di while al posto di do/while. codice ripetuto due volte
-1: errore di logica: i bordi appartengono a due mattonelle.
-6: tutte le funzioni mancanti o interfaccia errata
-3: errore grave x e y non vengono mai generate
-3: errore grave: array usano indice i (del granello) anziche` j (esperimento)
-2: errore grave: array di lunghezza pari a granelli

lcsr36

-2: media non prende la lunghezza di array come argomento e funzione inutile
-2: ciclo di N non deve essere in contapepe
-3: errore grave! x e y passati come arg puntatori a contaPepe ma non servono!
-3: errore di sintassi grave: media(&MA[RISPY], &MB[RISPY], &MC[RISPY], &NA, &NB, &NC);

lcsr37

-1: funzione contaPepe non fa quanto chiesto
-1: errore di logica: i bordi appartengono a due mattonelle.

lcsr38

-3: non compila
gravissimi errori di sintassi e non solo

lcsr39

-5: funzioni con interfaccia errata
-3: punti non nel cerchio
correggere con calma. diversi errori gravi
-3: non si calcola la media dei numeri richiesta
-2: gli array contengono dati errrati e comunque non vengono piu` usati
-3: errore logico in contaPepe
gravemente insufficiente

lcsr40

-2: contatori non azzerati!
-4: soluzione copiata PARI PARI dalla soluzione online dello scorso anno INCLUSO l’errore(!) e le parti non richieste

lcsr42

-1: media non prende la lunghezza di array come argomento
-4: la funzione contaPepe non fa quanto richiesto e interfaccia errata

lcsr44

-3: non compila
-5: errore funzione e generazione nel cerchio. errore di logica grave
-6: errori gravi di sintassi nell’uso di array e puntatori
-1: media non prende la lunghezza di array come argomento
-2: media non azzera la variabile somma
gravemente insufficiente

lcsr45

-1: media non prende la lunghezza di array come argomento
-1: in contaPepe le condizioni devono usare if/else if per evitare valutazioni inutili

lcsr46

-2: funzione media inutile e non prende la lunghezza degli array
-2: interfaccia genCirc perche` prende C??
-3: generate punti FUORI dal cerchio!

lcsr48

-1: media non prende la lunghezza di array come argomento
-1: le mattonelle hanno larghezze diverse: B e C trattano diversamente i bordi
-2: media non e` azzerata (warning ignorato!) prima di essere usata

lcsr50

-5: tutte le funzioni hanno interfacce errate
</pre>


   </div>
   <!-- end #content -->

   <div id="sidebar">
<div id="sidebar-bgtop"></div>

<div id="sidebar-content">
  <h3 class=h3sidebar>Last update: 12 Jan 2016</h3>

  <div class="sidemenu">
    <ul>
      <li><a href="../../material/esercitazione-11.pdf">testo</a></li>
      <li><a href="../../material/esercitazione-11.c">soluzione</a></li>
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
