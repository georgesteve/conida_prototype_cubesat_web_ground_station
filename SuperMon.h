/*


  OK, ya ready for some fun? HTML + CSS styling + javascript all in and undebuggable environment

  one trick I've learned to how to debug HTML and CSS code.

  get all your HTML code (from html to /html) and past it into this test site
  muck with the HTML and CSS code until it's what you want
  https://www.w3schools.com/html/tryit.asp?filename=tryhtml_intro

  No clue how to debug javascrip other that write, compile, upload, refresh, guess, repeat

  I'm using class designators to set styles and id's for data updating
  for example:
  the CSS class .tabledata defines with the cell will look like
  <td><div class="tabledata" id = "switch"></div></td>

  the XML code will update the data where id = "switch"
  java script then uses getElementById
  document.getElementById("switch").innerHTML="Switch is OFF";


  .. now you can have the class define the look AND the class update the content, but you will then need
  a class for every data field that must be updated, here's what that will look like
  <td><div class="switch"></div></td>

  the XML code will update the data where class = "switch"
  java script then uses getElementsByClassName
  document.getElementsByClassName("switch")[0].style.color=text_color;


  the main general sections of a web page are the following and used here

  <html>
    <style>
    // dump CSS style stuff in here
    </style>
    <body>
      <header>
      // put header code for cute banners here
      </header>
      <main>
      // the buld of your web page contents
      </main>
      <footer>
      // put cute footer (c) 2021 xyz inc type thing
      </footer>
    </body>
    <script>
    // you java code between these tags
    </script>
  </html>


*/

// note R"KEYWORD( html page code )KEYWORD"; 
// again I hate strings, so char is it and this method let's us write naturally

const char PAGE_MAIN[] PROGMEM = R"=====(<!DOCTYPE html>
<html lang="en" class="js-focus-visible">

<title>Web Page Update Demo</title>

<style>
   /* Estilos CSS para la separación entre main y footer */
   main {
            margin-bottom: 30px; /* Agrega un margen inferior de 20 píxeles al main */
        }


        /* Resto de tus estilos CSS existentes */

        .image.right {
            width: 40%;
            max-width: 10rem;
            float: right;
            margin: 0 1.5rem 1rem 0;
            top: 0.25rem;
        }

        .image img {
            display: block;
            border-radius: 4px;
            max-width: 100%;
            height: auto;
        }

        /* Estilo personalizado para el contenedor de la imagen */
        .image-container {
            float: right;
            width: 40%;
            margin: 0 0 1rem 1.5rem;
            top: 0.25rem;
        }

        /* Estilo personalizado para el gráfico */
        #voltageChartContainer {
            width: 600px;
            height: 400px;
            margin: 0 auto;
        }


  /* Estilo del encabezado/portada */
  .header {
      background-image: url('https://s1.eestatic.com/2020/10/28/omicrono/tecnologia/nanotecnologia-tecnologia-exploracion_espacial_531707936_163749259_1706x960.jpg');
      background-size: cover;
      background-position: center;
      height: 600px; /* Ajusta la altura según tus necesidades */
      color: #fff;
      text-align: center;
      display: flex;
      flex-direction: column;
      align-items: center;
      justify-content: center;
  }

  .header h1 {
      font-size: 48px;
      font-weight: bold;
      margin: 0;
  }

  /* Añade otros estilos a tu contenido debajo del encabezado */
  .content {
      padding: 20px;
      font-size: 16px; /* Tamaño de fuente más pequeño en el contenido */
  }


  /* Image */
  .image {
    border: 0;
    border-radius: 4px;
    display: inline-block;
    position: relative;
  }

  .image img {
    display: block;
    border-radius: 4px;
    max-width: 100%;
    height: auto;
  }

  .image.left, .image.right {
    width: 40%;
    max-width: 10rem;
    float: left;
    margin: 0 1.5rem 1rem 0;
    top: 0.25rem;
  }

  .image.right {
    float: right;
    max-width: 40%;
    margin: 0 0 1rem 1.5rem;
    top: 0.25rem;
  }

  .image.fit {
    display: block;
    margin: 0 0 2rem 0;
    max-width: 100%;
  }

  .image.fit img {
    width: 100%;
  }

  .image.main {
    display: block;
    margin: 0 0 3rem 0;
    max-width: 100%;
  }

  .image.main img {
    width: 100%;
  }

  /* Resto de estilos */
  table {
    position: relative;
    width: 100%;
    border-spacing: 0;
  }

  tr {
    border: 1px solid white;
    font-family: "Verdana", "Arial", sans-serif;
    font-size: 20px;
  }

  th {
    height: 20px;
    padding: 3px 15px;
    background-color: #343a40;
    color: #FFFFFF !important;
  }

  td {
    height: 20px;
    padding: 3px 15px;
  }

  .tabledata {
    font-size: 24px;
    position: relative;
    padding-left: 5px;
    padding-top: 5px;
    height: 25px;
    border-radius: 5px;
    color: #FFFFFF;
    line-height: 20px;
    transition: all 200ms ease-in-out;
    background-color: #00AA00;
  }

  .fanrpmslider {
    width: 30%;
    height: 55px;
    outline: none;
    height: 25px;
  }

  .bodytext {
    font-family: "Verdana", "Arial", sans-serif;
    font-size: 24px;
    text-align: left;
    font-weight: light;
    border-radius: 5px;
    display: inline;
  }

  .navbar {
    width: 100%;
    height: 50px;
    margin: 0;
    padding: 10px 0px;
    background-color: #FFF;
    color: #000000;
    border-bottom: 5px solid #293578;
  }

  .fixed-top {
    position: fixed;
    top: 0;
    right: 0;
    left: 0;
    z-index: 1030;
  }

  .navtitle {
    float: left;
    height: 50px;
    font-family: "Verdana", "Arial", sans-serif;
    font-size: 50px;
    font-weight: bold;
    line-height: 50px;
    padding-left: 20px;
  }

  .navheading {
    position: fixed;
    left: 60%;
    height: 50px;
    font-family: "Verdana", "Arial", sans-serif;
    font-size: 20px;
    font-weight: bold;
    line-height: 20px;
    padding-right: 20px;
  }

  .navdata {
    justify-content: flex-end;
    position: fixed;
    left: 70%;
    height: 50px;
    font-family: "Verdana", "Arial", sans-serif;
    font-size: 20px;
    font-weight: bold;
    line-height: 20px;
    padding-right: 20px;
  }

  .category {
    font-family: "Verdana", "Arial", sans-serif;
    font-weight: bold;
    font-size: 32px;
    line-height: 50px;
    padding: 20px 10px 0px 10px;
    color: #000000;
  }

  .heading {
    font-family: "Verdana", "Arial", sans-serif;
    font-weight: normal;
    font-size: 28px;
    text-align: left;
  }

  .btn {
    background-color: #444444;
    border: none;
    color: white;
    padding: 10px 20px;
    text-align: center;
    text-decoration: none;
    display: inline-block;
    font-size: 16px;
    margin: 4px 2px;
    cursor: pointer;
  }

  .foot {
    font-family: "Verdana", "Arial", sans-serif;
    font-size: 20px;
    position: relative;
    height: 30px;
    text-align: center;
    color: #AAAAAA;
    line-height: 20px;
    margin-top: 100px; /* Agrega un margen superior de 20 píxeles al footer */
  }

  .container {
    max-width: 1800px;
    margin: 0 auto;
  }

  table tr:first-child th:first-child {
    border-top-left-radius: 5px;
  }

  table tr:first-child th:last-child {
    border-top-right-radius: 5px;
  }

  table tr:last-child td:first-child {
    border-bottom-left-radius: 5px;
  }

  table tr:last-child td:last-child {
    border-bottom-right-radius: 5px;
  }
</style>
  <head><meta charset="utf-8" />

    <!-- Parte del grafico -->
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    <!-- Parte del grafico -->

</head>
  <body style="background-color: #efefef" onload="process()">

   <!-- Encabezado/portada con imagen de fondo -->
   <div class="header">
    <h1>KillaSAT Estación Terrena</h1>
    <div id="date">mm/dd/yyyy</div>
    <div id="time">00:00:00</div>
</div>
  
    <main class="container" style="margin-top:70px">
      <div class="category">Sensor Readings</div>


       <!-- Contenedor de la imagen -->
       <div class="image-container">
        <img src="https://drive.google.com/uc?export=view&id=1_v_XdlP0HcVn47Hp9MFjqskAUwxEBQd5" alt="Killa logo" height="500px">
    </div>

 


      <div style="border-radius: 10px !important;">
      <table style="width:50%">
      <colgroup>
        <col span="1" style="background-color:rgb(230,230,230); width: 20%; color:#000000 ;">
        <col span="1" style="background-color:rgb(200,200,200); width: 15%; color:#000000 ;">
        <col span="1" style="background-color:rgb(180,180,180); width: 15%; color:#000000 ;">
      </colgroup>
      <col span="2"style="background-color:rgb(0,0,0); color:#FFFFFF">
      <col span="2"style="background-color:rgb(0,0,0); color:#FFFFFF">
      <col span="2"style="background-color:rgb(0,0,0); color:#FFFFFF">
      <tr>
        <th colspan="1"><div class="heading">Variable</div></th>
        <th colspan="1"><div class="heading">Bits</div></th>
        <th colspan="1"><div class="heading">Volts</div></th>
      </tr>
      <tr>
        <td><div class="bodytext">Angular velocity (34)</div></td>
        <td><div class="tabledata" id = "b0"></div></td>
        <td><div class="tabledata" id = "v0"></div></td>
      </tr>
      <tr>
        <td><div class="bodytext">Panel Intensity (A) (35)</div></td>
        <td><div class="tabledata" id = "b1"></div></td>
        <td><div class="tabledata" id = "v1"></div></td>
      </tr>
        <tr>
        <td><div class="bodytext">Control Active</div></td>
        <td><div class="tabledata" id = "switch"></div></td>
      </tr>
      </table>

      
    </div>
    <br>
    
  
 
  
    <div class="category">Mission Controls</div>
    <br>
    <div class="bodytext">Run mission </div>
    <button type="button" class = "btn" id = "btn0" onclick="ButtonPress0()">Toggle</button>
    </div>
    <br>
    <div class="bodytext">Start control</div>
    <button type="button" class = "btn" id = "btn1" onclick="ButtonPress1()">Toggle</button>
    </div>
    <br>
    <br>
    <div class="bodytext">Reation Wheel Speed Control (RPM: <span id="fanrpm"></span>)</div>
    <br>
    <input type="range" class="fanrpmslider" min="0" max="255" value = "0" width = "0%" oninput="UpdateSlider(this.value)"/>
    <br>
    <br>

   <!-- Contenedor del gráfico -->
   <div id="voltageChartContainer">
    <canvas id="voltageChart" width="400" height="200"></canvas>

</div>


  </main>

<footer div class="foot" id="temp">Ground Station Web Page Creation and Data Update Demo</div>
  </body>


  <script type = "text/javascript">
  
    // global variable visible to all java functions
    var xmlHttp=createXmlHttpObject();

    // function to create XML object
    function createXmlHttpObject(){
      if(window.XMLHttpRequest){
        xmlHttp=new XMLHttpRequest();
      }
      else{
        xmlHttp=new ActiveXObject("Microsoft.XMLHTTP");
      }
      return xmlHttp;
    }

    // function to handle button press from HTML code above
    // and send a processing string back to server
    // this processing string is use in the .on method
    function ButtonPress0() {
      var xhttp = new XMLHttpRequest(); 
      var message;
      // if you want to handle an immediate reply (like status from the ESP
      // handling of the button press use this code
      // since this button status from the ESP is in the main XML code
      // we don't need this
      // remember that if you want immediate processing feedbac you must send it
      // in the ESP handling function and here
      /*
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          message = this.responseText;
          // update some HTML data
        }
      }
      */
       
      xhttp.open("PUT", "BUTTON_0", false);
      xhttp.send();
    }


    // function to handle button press from HTML code above
    // and send a processing string back to server
    // this processing string is use in the .on method
    function ButtonPress1() {
      var xhttp = new XMLHttpRequest(); 
      /*
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          document.getElementById("button1").innerHTML = this.responseText;
        }
      }
      */
      xhttp.open("PUT", "BUTTON_1", false);
      xhttp.send(); 
    }
    
    function UpdateSlider(value) {
      var xhttp = new XMLHttpRequest();
      // this time i want immediate feedback to the fan speed
      // yea yea yea i realize i'm computing fan speed but the point
      // is how to give immediate feedback
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          // update the web based on reply from  ESP
          document.getElementById("fanrpm").innerHTML=this.responseText;
        }
      }
      // this syntax is really weird the ? is a delimiter
      // first arg UPDATE_SLIDER is use in the .on method
      // server.on("/UPDATE_SLIDER", UpdateSlider);
      // then the second arg VALUE is use in the processing function
      // String t_state = server.arg("VALUE");
      // then + the controls value property
      xhttp.open("PUT", "UPDATE_SLIDER?VALUE="+value, true);
      xhttp.send();
    }

    // function to handle the response from the ESP
    function response(){
      var message;
      var barwidth;
      var currentsensor;
      var xmlResponse;
      var xmldoc;
      var dt = new Date();
      var color = "#e8e8e8";
     
      // get the xml stream
      xmlResponse=xmlHttp.responseXML;
  
      // get host date and time
      document.getElementById("time").innerHTML = dt.toLocaleTimeString();
      document.getElementById("date").innerHTML = dt.toLocaleDateString();
  
      // A0
      xmldoc = xmlResponse.getElementsByTagName("B0"); //bits for A0
      message = xmldoc[0].firstChild.nodeValue;
      
      if (message > 2048){
      color = "#aa0000";
      }
      else {
        color = "#0000aa";
      }
      
      barwidth = message / 40.95;
      document.getElementById("b0").innerHTML=message;
      document.getElementById("b0").style.width=(barwidth+"%");
      // if you want to use global color set above in <style> section
      // other wise uncomment and let the value dictate the color
      //document.getElementById("b0").style.backgroundColor=color;
      //document.getElementById("b0").style.borderRadius="5px";
      
      xmldoc = xmlResponse.getElementsByTagName("V0"); //volts for A0
      message = xmldoc[0].firstChild.nodeValue;
      document.getElementById("v0").innerHTML=message;
      document.getElementById("v0").style.width=(barwidth+"%");
      // you can set color dynamically, maybe blue below a value, red above
      document.getElementById("v0").style.backgroundColor=color;
      //document.getElementById("v0").style.borderRadius="5px";
  
      // A1
      xmldoc = xmlResponse.getElementsByTagName("B1");
      message = xmldoc[0].firstChild.nodeValue;
      if (message > 2048){
      color = "#aa0000";
      }
      else {
        color = "#0000aa";
      }
      document.getElementById("b1").innerHTML=message;
      width = message / 40.95;
      document.getElementById("b1").style.width=(width+"%");
      document.getElementById("b1").style.backgroundColor=color;
      //document.getElementById("b1").style.borderRadius="5px";
      
      xmldoc = xmlResponse.getElementsByTagName("V1");
      message = xmldoc[0].firstChild.nodeValue;
      document.getElementById("v1").innerHTML=message;
      document.getElementById("v1").style.width=(width+"%");
      document.getElementById("v1").style.backgroundColor=color;
      //document.getElementById("v1").style.borderRadius="5px";
  
      xmldoc = xmlResponse.getElementsByTagName("LED");
      message = xmldoc[0].firstChild.nodeValue;
  
      if (message == 0){
        document.getElementById("btn0").innerHTML="Turn ON";
      }
      else{
        document.getElementById("btn0").innerHTML="Turn OFF";
      }
         
      xmldoc = xmlResponse.getElementsByTagName("SWITCH");
      message = xmldoc[0].firstChild.nodeValue;
      document.getElementById("switch").style.backgroundColor="rgb(200,200,200)";
      // update the text in the table
      if (message == 0){
        document.getElementById("switch").innerHTML="Control Inactive";
        document.getElementById("btn1").innerHTML="Turn ON";
        document.getElementById("switch").style.color="#0000AA"; 
      }
      else {
        document.getElementById("switch").innerHTML="Control Active";
        document.getElementById("btn1").innerHTML="Turn OFF";
        document.getElementById("switch").style.color="#00AA00";
      }
     }
  
    // general processing code for the web page to ask for an XML steam
    // this is actually why you need to keep sending data to the page to 
    // force this call with stuff like this
    // server.on("/xml", SendXML);
    // otherwise the page will not request XML from the ESP, and updates will not happen
    function process(){
     
     if(xmlHttp.readyState==0 || xmlHttp.readyState==4) {
        xmlHttp.open("PUT","xml",true);
        xmlHttp.onreadystatechange=response;
        xmlHttp.send(null);
      }       
        // you may have to play with this value, big pages need more porcessing time, and hence
        // a longer timeout
        setTimeout("process()",100);
    }
  
  //Aquí inicia el gráfico

  const maxDataPoints = 20;
        const initialData = Array(maxDataPoints).fill(null);
        const initialLabels = Array.from({ length: maxDataPoints }, (_, i) => '');

        const chartData = {
            labels: initialLabels,
            datasets: [
                {
                    label: 'Pin V0 (V)',
                    data: initialData,
                    borderColor: 'rgba(75, 192, 192, 1)',
                    borderWidth: 2,
                    fill: false,
                    cubicInterpolationMode: 'default',
                }
            ]
        };

        const voltageConfig = {
            type: 'line',
            data: chartData,
            options: {
                responsive: true,
                maintainAspectRatio: false,
                scales: {
                    x: {
                        beginAtZero: true,
                        display: true,
                        scaleLabel: {
                            display: true,
                            labelString: 'Tiempo',
                        },
                    },
                    y: {
                        beginAtZero: true,
                        suggestedMax: 5,
                        display: true,
                        scaleLabel: {
                            display: true,
                            labelString: 'Voltaje (V)',
                        },
                    },
                },
                animation: {
                    duration: 1000,
                    easing: 'linear',
                },
                plugins: {
                    legend: {
                        display: true,
                    },
                },
            },
        };

        const voltageCtx = document.getElementById('voltageChart').getContext('2d');
        const voltageChart = new Chart(voltageCtx, voltageConfig);

        function addVoltageData(v0) {
            const currentTime = new Date().toLocaleTimeString();

            chartData.labels.shift();
            chartData.labels.push(currentTime);
            chartData.datasets[0].data.shift();
            chartData.datasets[0].data.push(v0);

            voltageChart.update();
        }

        function obtenerDatosEnTiempoReal() {
            
            const v0 = parseFloat(document.getElementById("v0").textContent);

            addVoltageData(v0);

            setTimeout(obtenerDatosEnTiempoReal, 1000);
        }

        obtenerDatosEnTiempoReal();


  </script>

</html>
)=====";
