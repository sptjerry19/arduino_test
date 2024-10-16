//Khai báo biến chứa mã nguồn html dùng const char* R"html
const char* htmled = R"html(
<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <style>
      body {
        background: linear-gradient(-45deg, #ee7752, #e73c7e, #23a6d5, #23d5ab);
        background-size: 400% 400%;
        animation: gradient 15s ease infinite;
        height: 100vh;
      }

      @keyframes gradient {
        0% {
          background-position: 0% 50%;
        }

        50% {
          background-position: 100% 50%;
        }

        100% {
          background-position: 0% 50%;
        }
      }

      .draw-border {
        box-shadow: inset 0 0 0 4px #58afd1;
        color: #58afd1;
        transition: color 0.25s 0.0833333333s;
        position: relative;
      }

      .draw-border::before,
      .draw-border::after {
        border: 0 solid transparent;
        box-sizing: border-box;
        content: "";
        pointer-events: none;
        position: absolute;
        width: 0;
        height: 0;
        bottom: 0;
        right: 0;
      }

      .draw-border::before {
        border-bottom-width: 4px;
        border-left-width: 4px;
      }

      .draw-border::after {
        border-top-width: 4px;
        border-right-width: 4px;
      }

      .draw-border:hover {
        color: #ffe593;
      }

      .draw-border:hover::before,
      .draw-border:hover::after {
        border-color: #ffe593;
        transition: border-color 0s, width 0.25s, height 0.25s;
        width: 100%;
        height: 100%;
      }

      .draw-border:hover::before {
        transition-delay: 0s, 0s, 0.25s;
      }

      .draw-border:hover::after {
        transition-delay: 0s, 0.25s, 0s;
      }

      .btn {
        background: none;
        border: none;
        cursor: pointer;
        line-height: 1.5;
        font: 700 1.2rem "Roboto Slab", sans-serif;
        padding: 1em 2em;
        letter-spacing: 0.05rem;
      }

      .btn:focus {
        outline: 2px dotted #55d7dc;
      }

      .btn_led {
        margin: 0 20px;
      }

      .content_btn_led {
        display: flex;
        justify-content: center;
        min-width: 500px;
        width: 50%;
      }

      #content {
        display: flex;
        justify-content: center;
        width: 70%;
        height: 70vh;
        background-color: #fff;
        margin: 40px auto;
        opacity: 0.7;
        border-radius: 20px;
      }

      .content_modal {
        display: flex;
        justify-content: center;
        width: 80%;
      }

      .btn_group {
        margin: auto;
      }
    </style>
  </head>

  <body>
    <header></header>
    <div id="content">
      <div class="content_modal">
        <div class="btn_group">
          <a href="/led/on">
            <button
              class="btn draw-border btn_led"
            >
              Led on
            </button>
          </a>
          <a href="/led/off">
            <button
              class="btn draw-border btn_led"
            >
              Led off
            </button>
          </a>
        </div>
      </div>
    </div>
    <script>
    window.onload = updateD8;
      function updateD8() {
        var xhttp = new XMLHttpRequest();
        xhttp.open("GET", "/D8.html", true);
        xhttp.send();
      }</script>
  </body>
</html>


)html";