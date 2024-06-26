let arr=[];
function addTodo()
{
    let holder1=document.querySelector('.todo-text').value;
    let holder2=document.querySelector('.due-date').value;
    //console.log(holder)
        if(holder1!='' && holder2!='')
            {
                arr.push({name:holder1,
                    duedate:holder2});
               
                document.querySelector('.todo-text').value="";
               document.querySelector('.due-date').value='';
                 
               

            }
            else 
            {
                alert("there is no todo name");
            }
            renderlists();
            
         
            
            

}
function renderlists()
         {
               
            
            
            document.querySelector(`.todo_display`).innerHTML=``;
            for( let i=0;i<arr.length;i++)
                {     let  arrobj=arr[i];
                    let {name,duedate}=arrobj;
                    document.querySelector(`.todo_display`).innerHTML+=`<div>${name}</div> <div> ${duedate}</div> <div><button class="delete-button" onclick="arr.splice(${i},1);
                        renderlists();">Delete</button></div>`;
                }
         }