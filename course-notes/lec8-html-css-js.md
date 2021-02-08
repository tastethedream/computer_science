# CS50 Lecture 8 HTML CSS and Javascript

(Course migrates to 2021 from this point)

## Internet Protocol (IP)

- Standerises how computers address each other

## Domain Name System (DNS)

- Translates domain names to IP addressess

- Sevice provided by your ISP (Internet Service Provider)

## Transmission Control Protocal (TCP)

- Governs what goes on the outside of the envelopes

- Port Numbers
    -  80 webpage (HTTP)
    - 443 secure webpage (HTTPS)


## Hypertext Transfer Protocol (HTTP)

- Governs what goes on the inside of the envelopes

- GET

    - request
        GET / HTTP/1.1
        Host: www.example.com/index.html

    -response
        HTTP/1.1 200 ok
        Content-Type: text/html

- POST
    - Makes GET requests private



## Status codes

200 ok
301 Moved permanently
302 found
304 not modified
307 temporary redirect
401 Unauthorised
403 forbidden
404 not found
418 i'm a teapot
500 internal server error
503 service unavailable

## Hypertext Markup language (HTML)

### CS50 IDE

#### Server 

    - $ http-server
    - click open on the available port to view what is available
    - click on the file you require to see your page

## Javascript

### document.querySelector

    Allows you to select any HTML element 

    `let name = document.querySelector('#name').value`


    ```
    <script>

      document.addEventListener('DOMContentLoaded', function(){
          document.querySelector('form').addEventListener('submit', function(){
              let name = document.querySelector('#name).value;
            alert('Hello, ' + name);
          });
      });
              
    </script>

    <form onsubmit="greet(); retrun false;">
        <input autocomplete="off" autofocus id="name" placeholder"What is your name">
        <input type= "submit" value="Greet Me>
    </form>
    ```

### Javascript Events

- blur
- change
- click
- drag
- focus
- keyup
- load
- mousedown
- mouseover
- mouseip
- submit
- touchmove
- unload

### Location

```
<script>
navigator.geolocation.getCurrentPosition(function(position) {
    document.write(position.coords.latitude + position.coords.longitude);
});
</script>
```



