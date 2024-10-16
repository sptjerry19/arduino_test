const char* admin = R"html(
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
      .weather {
        width: 70%;
        position: relative;
        background-color: aliceblue;
        padding: 30px 40px;
        border-radius: 40px;
        box-shadow: 3px 3px #cbcbcb;
      }
      .weather_header {
      }
      .weather_header--date-time {
        font-size: 15px;
      }
      .weather_header--location {
        margin: 0;
      }
      .weather_header--icon {
        margin-top: 50px;
        padding-right: 20px;
        font-size: 100px;
        position: absolute;
        top: 0;
        right: 0;
      }
      .weather_header--temp {
        margin: 5px 0;
        padding-bottom: 10px;
        border-bottom: 1px solid #4242423f;
      }
      .weather_content {
        margin-top: 15px;
        display: flex;
        flex-direction: row;
        justify-content: space-around;
      }
      .weather_content--temp_vn {
        display: flex;
        flex-direction: column;
        align-items: center;
        background-color: #e3e0ff;
        padding: 15px;
        box-shadow: 3px 3px #cbcbcb;
        border-radius: 20px;
      }
      .weather_content--temp_vn--name {
        font-size: 20px;
      }
      .weather_content--temp_vn--icon {
        margin-top: 5px;
        color: #00009f;
      }
      .weather_content--temp_vn--data {
        margin-top: 8px;
        font-size: 15px;
      }
      .weather_content--temp_ny {
        margin-left: 8px;
        display: flex;
        flex-direction: column;
        align-items: center;
        background-color: #e3e0ff;
        padding: 15px;
        box-shadow: 3px 3px #cbcbcb;
        border-radius: 20px;
      }
      .weather_content--temp_ny--name {
        font-size: 20px;
      }
      .weather_content--temp_ny--icon {
        margin-top: 5px;
        color: #00009f;
      }
      .weather_content--temp_ny--data {
        margin-top: 8px;
        font-size: 15px;
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
      <div class="weather">
        <div class="weather_header">
          <h1 class="weather_header--date-time">Time</h1>
          <p class="weather_header--location">Room</p>
          <h2 class="weather_header--temp">24C</h2>
          <p class="weather_header--icon">☀</p>
        </div>
        <div class="weather_content">
          <div class="weather_content--temp_vn">
            <div class="weather_content--temp_vn--name">Hà Nội</div>
            <div class="weather_content--temp_vn--icon">icon</div>
            <div class="weather_content--temp_vn--data">26C</div>
          </div>
          <div class="weather_content--temp_ny">
            <div class="weather_content--temp_ny--name">New York</div>
            <div class="weather_content--temp_ny--icon">icon</div>
            <div class="weather_content--temp_ny--data">18C</div>
          </div>
        </div>
      </div>
    </div>
    <footer></footer>

    <script>
      const apiKey = "1b3d57ebe410a34ccb74c116bbf2832a";

      const getWeather = async (location) => {
        const response = await fetch(
          `https://api.openweathermap.org/data/2.5/weather?q=${location}&appid=${apiKey}`
        );

        if (response.status === 200) {
          const data = await response.json();
          return data;
        } else {
          throw new Error(response.statusText);
        }
      };
      // get API at HANOI
      getWeather("Ha%20Noi,VN").then((data) => {
        const { main, weather } = data;

        const temperature = Number.parseFloat(main.temp - 273).toFixed(2);
        const humidity = main.humidity;
        const description = weather[0].description;

        const weatherHTML = `
            ${temperature} &deg;C
            </br>
            ${humidity}%
        `;

        const iconHTML = `${description}`;

        document.querySelector(".weather_content--temp_vn--icon").innerHTML =
          iconHTML;

        document.querySelector(".weather_content--temp_vn--data").innerHTML =
          weatherHTML;
      });
      // get API at NewYork
      getWeather("New%20York,US").then((data) => {
        const { main, weather } = data;

        const temperature = Number.parseFloat(main.temp - 273).toFixed(2);
        const humidity = main.humidity;
        const description = weather[0].description;

        const weatherHTML = `
            ${temperature} &deg;C
            </br>
            ${humidity}%
        `;

        const iconHTML = `${description}`;

        document.querySelector(".weather_content--temp_ny--icon").innerHTML =
          iconHTML;

        document.querySelector(".weather_content--temp_ny--data").innerHTML =
          weatherHTML;
      });
      // get API at now
      var xhttp = new XMLHttpRequest();
      // Set the Access-Control-Allow-Origin header
      setInterval(() => {
        const date = new Date();
        const str = date.toLocaleString("en-us", {
          hour12: true,
          weekday: "short",
          hour: "2-digit",
          month: "long",
          year: "numeric",
        });
        document.querySelector(".weather_header--date-time").innerHTML = str;
        xhttp.onreadystatechange = function () {
          if (this.readyState == 4 && this.status == 200) {
            // Typical action to be performed when the document is ready:
            const data = JSON.parse(xhttp.responseText);
            let icon;
            if (data.temperature > 30) {
              icon = "♨";
            } else if (data.temperature < 20) {
              icon = "❆";
            } else {
              icon = "☀";
            }

            document.querySelector(".weather_header--icon").innerHTML = icon;
            document.querySelector(".weather_header--temp").innerHTML = `
                                  <p class="text-4xl">${data.temperature}&deg;C</p>
                                  <p>Độ ẩm: ${data.humidity}%</p>
                  `;
          }
        };
        xhttp.open("GET", "/data", true);
        xhttp.setRequestHeader("Access-Control-Allow-Origin", "*");
        xhttp.send();
      }, 100);
    </script>
  </body>
</html>


)html";