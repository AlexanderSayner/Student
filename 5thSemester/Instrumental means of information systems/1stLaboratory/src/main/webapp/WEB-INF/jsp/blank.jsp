<!DOCTYPE html>
<%@ page contentType="text/html;charset=utf-8" %>

<html lang="en">
<head>

    <meta charset="UTF-8">

    <link rel="stylesheet" type="text/css"
          href="webjars/bootstrap/3.3.7/css/bootstrap.min.css"/>

    <link rel="stylesheet" type="text/css"
          href="css/blankStyle.css"/>

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
            <input type="text" name="year" value="20" placeholder="год" size="3"> г.
        </div>


    </div>

</div>
<!-- /.container -->

<script type="text/javascript"
        src="webjars/bootstrap/3.3.7/js/bootstrap.min.js"></script>

</body>

</html>
