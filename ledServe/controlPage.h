const char* control = R"html(
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>IOT team7</title>
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

      nav {
        margin: 50px auto;
        width: 290px;
      }

      menu {
        border-radius: 3px;
        position: fixed;
        z-index: 2;
        top: 20px;
        background-color: black;
        padding-left: 0;
        margin-left: 40px;
      }

      menu:after,
      menu:before {
        display: block;
        content: " ";
      }

      menu:after {
        clear: both;
      }

      li {
        list-style-type: none;
        background: linear-gradient(
          rgba(220, 220, 255, 0.4) 85%,
          rgba(255, 255, 255, 0.5) 100%
        );

        float: left;
        cursor: pointer;
        padding: 3px 10px;
        border-top: 2px solid rgba(200, 200, 255, 0.5);
        border-bottom: 2px solid rgba(50, 50, 50, 0.4);
      }

      li:first-child {
        border-radius: 5px 0 0 5px;
      }

      li:last-child {
        border-radius: 0 5px 5px 0;
      }

      a {
        display: block;
        padding: 10px 13px;
        font-size: 26px;
        text-decoration: none;
        border-radius: 5px;
        position: relative;
        top: 0;
        color: #fff;
        transition: all 0.4s;
      }

      li:hover a {
        top: -20px;
        color: #4eacff;
        background-color: #fff;
        box-shadow: 0 0 5px 0 rgba(255, 255, 255, 0.7);
        transition: all 0.4s;
      }

      li a:after {
        display: block;
        content: "";
        position: absolute;
        top: 100%;
        left: 42%;
        border-style: solid;
        border-color: transparent;
        border-width: 5px 5px 0 5px;
        transition: all 0.4s;
      }

      li:hover a:after {
        border-color: white transparent transparent transparent;
        transition: all 0.4s;
      }

      /*************************************/

      .menu2 {
        width: 350px;
      }

      .menu2 a {
        font-family: georgia;
        font-size: 14px;
        font-style: italic;
        text-transform: capitalize;
      }

      .menu2 li {
        border-right: 1px solid rgba(200, 200, 255, 0.5);
        border-left: 1px solid rgba(40, 40, 40, 0.2);
      }

      .selected {
        top: -20px;
        color: #4eacff;
        background-color: #fff;
        box-shadow: 0 0 5px 0 rgba(255, 255, 255, 0.7);
        transition: all 0.4s;
      }

      .selected:after {
        border-color: white transparent transparent transparent;
        transition: all 0.4s;
      }

      a.fun {
        display: none;
      }
      #content {
        margin-top: 150px;
        display: flex;
        flex-direction: column;
        justify-content: center;
        align-items: center;
      }
      .button-29 {
        align-items: center;
        appearance: none;
        background-image: radial-gradient(
          100% 100% at 100% 0,
          #5adaff 0,
          #5468ff 100%
        );
        border: 0;
        border-radius: 6px;
        box-shadow: rgba(45, 35, 66, 0.4) 0 2px 4px,
          rgba(45, 35, 66, 0.3) 0 7px 13px -3px,
          rgba(58, 65, 111, 0.5) 0 -3px 0 inset;
        box-sizing: border-box;
        color: #fff;
        cursor: pointer;
        display: inline-flex;
        font-family: "JetBrains Mono", monospace;
        height: 48px;
        justify-content: center;
        line-height: 1;
        list-style: none;
        overflow: hidden;
        padding-left: 16px;
        padding-right: 16px;
        position: relative;
        text-align: left;
        text-decoration: none;
        transition: box-shadow 0.15s, transform 0.15s;
        user-select: none;
        -webkit-user-select: none;
        touch-action: manipulation;
        white-space: nowrap;
        will-change: box-shadow, transform;
        font-size: 18px;
      }

      .button-29:focus {
        box-shadow: #3c4fe0 0 0 0 1.5px inset, rgba(45, 35, 66, 0.4) 0 2px 4px,
          rgba(45, 35, 66, 0.3) 0 7px 13px -3px, #3c4fe0 0 -3px 0 inset;
      }

      .button-29:hover {
        box-shadow: rgba(45, 35, 66, 0.4) 0 4px 8px,
          rgba(45, 35, 66, 0.3) 0 7px 13px -3px, #3c4fe0 0 -3px 0 inset;
        transform: translateY(-2px);
      }

      .button-29:active {
        box-shadow: #3c4fe0 0 3px 7px inset;
        transform: translateY(2px);
      }

      /* CSS */
      .button-4 {
        height: 50px;
        appearance: none;
        background-color: #fafbfc;
        border: 1px solid rgba(27, 31, 35, 0.15);
        border-radius: 6px;
        box-shadow: rgba(27, 31, 35, 0.04) 0 1px 0,
          rgba(255, 255, 255, 0.25) 0 1px 0 inset;
        box-sizing: border-box;
        color: #24292e;
        cursor: pointer;
        display: inline-block;
        font-family: -apple-system, system-ui, "Segoe UI", Helvetica, Arial,
          sans-serif, "Apple Color Emoji", "Segoe UI Emoji";
        font-size: 14px;
        font-weight: 500;
        line-height: 20px;
        list-style: none;
        padding: 6px 16px;
        position: relative;
        transition: background-color 0.2s cubic-bezier(0.3, 0, 0.5, 1);
        user-select: none;
        -webkit-user-select: none;
        touch-action: manipulation;
        vertical-align: middle;
        white-space: nowrap;
        word-wrap: break-word;
      }

      .button-4:hover {
        background-color: #f3f4f6;
        text-decoration: none;
        transition-duration: 0.1s;
      }

      .button-4:disabled {
        background-color: #fafbfc;
        border-color: rgba(27, 31, 35, 0.15);
        color: #959da5;
        cursor: default;
      }

      .button-4:active {
        background-color: #edeff2;
        box-shadow: rgba(225, 228, 232, 0.2) 0 1px 0 inset;
        transition: none 0s;
      }

      .button-4:focus {
        outline: 1px transparent;
      }

      .button-4:before {
        display: none;
      }

      .button-4:-webkit-details-marker {
        display: none;
      }

      .controls {
        margin-top: 40px;
        padding: 40px;
        background-color: #df7e7e3f;
        border-radius: 20px;
        box-shadow: 5px 5px #cbcbcb;
      }

      .controls_led {
        display: flex;
        justify-content: center;
      }

      .controls_motor {
        margin-top: 20px;
        display: flex;
        justify-content: center;
        align-items: center;
      }

      .controls_motor_group {
        display: flex;
        flex-direction: column;
        align-items: center;
      }
      .text-30 {
        font-size: 30px;
      }
      .controls_auto {
        display: flex;
      }
    </style>
  </head>

  <body>
    <header>
      <nav>
        <menu>
          <li><a href="#content">❖</a></li>
          <li><a href="/">☀</a></li>
          <li><a href="/control">☢</a></li>
        </menu>
      </nav>
    </header>
    <div id="content">
      <div class="controls">
        <!-- HTML !-->
        <div class="controls_led">
          <a href="/led/on"
            ><button class="button-29" role="button">Led ON</button></a
          >
          <a href="/led/off"
            ><button class="button-29" role="button">Led OFF</button></a
          >
        </div>
        <div class="controls_auto">
          <a href="/auto/on"
            ><button class="button-29" role="button">AUTO ON</button></a
          >
          <a href="/auto/off"
            ><button class="button-29" role="button">AUTO OFF</button></a
          >
        </div>
        <div class="controls_motor">
          <!-- HTML !-->
          <a href="/motor/left"
            ><button class="button-4 text-30" role="button">⇦</button></a
          >
          <div class="controls_motor_group">
            <a href="/motor/foward"
              ><button class="button-4 text-30" role="button">⇧</button></a
            >
            <a href="/motor/return"
              ><button class="button-4 text-30" role="button">⇩</button></a
            >
          </div>
          <a href="/motor/right">
            <button class="button-4 text-30" role="button">⇨</button> </a>
        </div>
      </div>
    </div>
    <footer></footer>
    <script>
      function sendEventAuto(event) {
        const events = {
          event: event,
        };

        // Chuyển đổi đối tượng JsonDocument thành chuỗi JSON
        const json = JSON.stringify(events);

        // Gửi chuỗi JSON qua cổng nối tiếp
        Serial.write(json);

        mySerial.write(json);
      }
    </script>
  </body>
</html>


)html";