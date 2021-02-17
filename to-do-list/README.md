# CS50 Final Project
## Forget Me Not

-  Video Demo <https://youtu.be/idAXMPlIEFk>

### Description

Whilst studying for CS50 I discovered two things. I am reaaly interested in the 
web design elements we covered and I am always writing to-do lists. These lists
are everywhere, on scraps of paper, in various note books. So why not design and 
build a web application to create these lists that rule my life.

Forget Me not allows you to enter a task that want to complete, mark is done and 
delete task from the list.

### Languages

I have chosen to write this application using Javascript, HTML and CSS.

### Files

I have written this project to be run in Node, using `npm start`.The code for this 
can be found in `index.js` I have included a brief description of each file used below. 

#### views/index.hbs

This file contains the projects HTML. It's main purpose is to manage the stucture 
of the rendered page. I used HTML to add the main heading, text, user input box and
add button.

#### public/css/styles/css

I have used CSS to take care of all styling for the page. This has allowed mr to 
manipulate colours, space and fonts. I have also used CSS to add in some nice
effects, for example, the list items shange colour when hovered over by the user. 

#### public/img/sky.jpeg

Any images used for this project are kept in this location to allow them to be
accessed from any file. In this version of the project I have only used a background
image in the CSS.

#### public/scripts/app.js

The Javascript files contain the functionality of the application. The main functions 
of this application are as follows:-

  - The users input is added to the list once the `add` buttton has been clicked.
  - The list item is then shown on screen.
  - When the user clickes on the list item to comfirm completeion of the task, the
  item is recorded as `done`.
  - Once the item is done, the completed task text is crossed out and the colour 
  is changed.
  - If the user clickes the red cross, the task is deleted from the list. 

### Conclusion

I feel this project has allowed me to display the skills I acquired whist studying CS50.
To further enhance these skills I plan to continue work on this application to improve the 
following:-

- When the application is refreshed it does not store or save the list.
- It is not currently possible to have multiple lists.
