<!DOCTYPE html>
<%@ page contentType="text/html;charset=utf-8" %>

<html lang="en">
<head>

    <meta charset="UTF-8">

    <link rel="stylesheet" type="text/css"
          href="/webjars/bootstrap/3.3.7/css/bootstrap.min.css"/>

          <style>
            table{
              margin: 50px 0;
              text-align: left;
              border: 1px solid #ddd;
              border-spacing: 10px;
              border-radius: 3px;
              background: #fdfdfd;
              font-size: 14px;
              width: auto;
            }
            td,th{
              border: 1px solid #ddd;
              padding: 5px;
              border-radius: 3px;
            }
            th{
              background: #E4E4E4;
            }
            caption{
              font-style: italic;
              text-align: right;
              color: #547901;
            }
          </style>

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

          <p align="center" >Образец обложки</p>
          <p align="right">Унифицированная форма № КО-4</p>
          <p align="right">Утверждена постановлением Госкомстата</p>
          <p align="right">России от 18.08.98 №88</p>

          <table align="right">
            <tr>
              <td>Строка1 Ячейка1</td>
            </tr>
            <tr>
              <td>Строка2 Ячейка1</td>
            </tr>
            <tr>
              <td>Строка3 Ячейка1</td>
            </tr>
            <tr>
              <td>Строка4 Ячейка1</td>
            </tr>
          </table>

    </div>

</div>
<!-- /.container -->

<script type="text/javascript"
        src="webjars/bootstrap/3.3.7/js/bootstrap.min.js"></script>

</body>

</html>
