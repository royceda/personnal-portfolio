<!DOCTYPE html>
<html>
<head>
   <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
   <title>Test DHTMLX</title>
   <script src="./codebase/dhtmlx.js" type="text/javascript"></script>
   <script src="./codebase/connector/codebase/connector.js" type="text/javascript"></script>
   <link rel="STYLESHEET" type="text/css" href="codebase/dhtmlx.css"></link>
   <style>
   html, body{
      width: 100%;
      height: 100%;
      overflow: hidden;
      margin: 0px;
      background-color: white;
   }
   </style>
</head>


<body>
   <script type="text/javascript">
   dhtmlxEvent(window,"load",function(){
      var layout = new dhtmlXLayoutObject(document.body,"2U");
      layout.cells("a").setText("Contacts");
      layout.cells("b").setText("Details");
      layout.cells("b").setWidth("500");

      var menu = layout.attachMenu();
      menu.loadXML("data/menu.xml");

      var toolbar = layout.attachToolbar();
      toolbar.setIconsPath("icons/");
      toolbar.loadXML("data/toolbar.xml");

      var contactsGrid = layout.cells("a").attachGrid();
      contactsGrid.setHeader("Name,Last Name,email");
      contactsGrid.setColumnIds("fname,lname,email");
      contactsGrid.setInitWidths("250,250,*");
      contactsGrid.setColAlign("left,left,left");
      contactsGrid.setColTypes("ro,ro,ro");
      contactsGrid.setColSorting("str,str,str");
      contactsGrid.attachHeader("#text_filter,#text_filter,#text_filter");
      contactsGrid.init();
      contactsGrid.load("data/contacts.php");

      var contactForm = layout.cells("b").attachForm();
      contactForm.loadStruct("data/form.xml");
      contactForm.bind(contactsGrid);


      var dpg = new dataProcessor("data/contacts.php");
      dpg.init(contactsGrid);

      contactForm.attachEvent("onButtonClick", function(name, command){
         contactForm.save();
      });

      toolbar.attachEvent("onclick",function(id){
         if(id == "newContact"){
            var rowId = contactsGrid.uid();
            var pos = contactsGrid.getRowsNum();
            contactsGrid.addRow(rowId, ["new", "", ""],pos);
         };
         if( id == "delContact"){
            var rowId = contactsGrid.getSelectedRowId();
            var rowIndex = contactsGrid.getRowIndex(rowId);
            if(rowId != null){
               contactsGrid.deleteRow(rowId);
               if(rowIndex != contactsGrid.getRowsNum -1){
                  contactsGrid.selectRow(rowIndex+1, true);
               }else{
                  contactsGrid.selectRow(rowIndex-1,true);
               }
            }
         }
      });

      dpg.attachEvent("onAfterUpdate", function(sid, action, tid, tag){
         if(action == "inserted"){
            contactsGrid.selectRowById(tid);
            contactForm.setFocusOnFirstActive();
         };
      });


   });


   </script>

</body>
</html>
