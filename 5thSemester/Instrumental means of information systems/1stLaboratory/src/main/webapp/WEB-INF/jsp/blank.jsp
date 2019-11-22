<!DOCTYPE html>
<%@ page contentType="text/html;charset=utf-8" %>

<html lang="en">
<head>

    <meta charset="UTF-8">

    <link rel="stylesheet" type="text/css"
          href="webjars/bootstrap/3.3.7/css/bootstrap.min.css"/>

    <link rel="stylesheet" type="text/css"
          href="css/blankStyle.css"/>

          <script>
          function CallPrint(strid) {
            var prtContent = document.getElementById(strid);
            var x = document.getElementById('textbox_id').value;
            var prtCSS = '<link rel="stylesheet" href="/templates/css/template.css" type="text/css" />';
            var WinPrint = window.open('','','left=50,top=50,width=800,height=640,toolbar=0,scrollbars=1,status=0');
            WinPrint.document.write('<div id="print" class="contentpane">');
            WinPrint.document.write(prtCSS);
            WinPrint.document.write(prtContent.innerHTML);
            WinPrint.document.write(x);
            WinPrint.document.write('</div>');
            WinPrint.document.close();
            WinPrint.focus();
            WinPrint.print();
            WinPrint.close();
            prtContent.innerHTML=strOldOne;
          }
          </script>

</head>
<body>

<nav class="navbar navbar-inverse">
    <div class="container">
        <div class="navbar-header">
            <a class="navbar-brand" href="#">Spring Boot</a>
        </div>
        <div id="navbar" class="collapse navbar-collapse">
            <ul class="nav navbar-nav">
                <li><a href="/">На главную</a></li>
                <li class="active"><a href="/blank">Бланк</a></li>
            </ul>
        </div>
    </div>
</nav>

<div class="container">

    <div class="starter-template">

        <div id="print-content">

        <p align="center">Образец обложки</p>
        <p align="right">Унифицированная форма № КО-4</p>
        <p align="right">Утверждена постановлением Госкомстата</p>
        <p align="right">России от 18.08.98 №88</p>

        <table align="right">
            <tr>
                <td>Код</td>
            </tr>
            <tr>
                <td>0310004</td>
            </tr>
        </table>

        <form>
            Организация:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <input type="text" name="organization" value="" size="30"> <br> <br>
            Структурное подразделение: <input type="text" name="department" value="" size="30">
        </form>

        <div align="center">
            <p id="textFont">Кассовая книга</p>
            на
            <input type="text" name="number" value="" placeholder="день" size="3">
            <input type="text" name="month" value="" placeholder="месяц" size="3">
            <input id="textbox_id" type="text" name="year" value="20" placeholder="год" size="3"> г.
        </div>

        </div>

        <a onClick="javascript:CallPrint('print-content');" title="Распечатать проект">Распечатать</a>

    </div>

</div>
<!-- /.container -->

<script type="text/javascript"
        src="webjars/bootstrap/3.3.7/js/bootstrap.min.js"></script>

</body>

</html>
