var result=""; 
const score=JSON.parse(localStorage.getItem('score'))
   ||{
    wins:0,
    losses:0,
    ties:0,
    total:0
  };


    update_score();
      function randomNumber()
    {  var num=Math.random();
        if(num>=0 && num <0.35)
        return "Scissor";
        else if(num>=0.35 && num<0.66)
        return "Paper";
        else if(num>=0.66 && num<1)
        return "Rock";
    }
        function Result()
        {
            document.querySelector(".js-result").innerHTML=result;
        }
    function update_score()
    {    
        document.querySelector(".update-score")
        .innerHTML=`wins: ${score.wins},  Losses:  ${score.losses},  Ties: ${score.ties},  Total Attempts: ${score.total}`;

    }
    

    function  fun2(parameter)
    {  
       
        if(parameter==="Reset")
        {   
            score.wins=0;
            score.losses=0;
            score.ties=0;
            score.total=0;
            localStorage.setItem('score', JSON.stringify(score));
            return  update_score();
            
              
        }
        computerMove=randomNumber();
       

        if(parameter==='Scissor')
        {
            if(computerMove==='Scissor')
            {
                result = 'tie.';
            }
            else if(computerMove==='Paper')
            {
                result = 'You Lose!';
            }
            else if (computerMove==='Rock')
            {
                result = 'You Win!';
           }
         
        }
        else if (parameter === 'Rock')
        {
            if(computerMove==='Rock')
            {
                result='tie.';
            }
            else if (computerMove==='Scissor')
            {
                result='You Win!';
            }
            else if (computerMove==='Paper')
            {
                result='You Lose!';
            }
        }
        else if(parameter==='Paper')
        {
            if(computerMove=== 'Paper')
            {
                result='tie.'
            }
            else if(computerMove==='Scissor')
            {
                result='You Win!';
            }
            else if(computerMove==='Rock')
            {
                result='You Lose!';
            }


        }
        {
            if(result==='tie.')
        {   score.ties+=1;
            score.total+=1;

        }
        else if(result==='You Win!')
        {
            score.wins+=1;
            score.total+=1;

        }
        else if(result==='You Lose!')
        {
            score.losses+=1;
            score.total+=1;
        }
        
         
          localStorage.setItem( "score", JSON.stringify(score));
          update_score();
          document.querySelector(".choice").innerHTML=`you  <img src="/AddtionalPractice/practicefile_js/rock-paper-and-scissor-img/${parameter}-emoji.png" class="result" >   <img  src="/AddtionalPractice/practicefile_js/rock-paper-and-scissor-img/${computerMove}-emoji.png" class="result"> computer`;
          document.querySelector(".js-result").innerHTML=Result;
         // Result();
          
        

        }

       // alert(`your picked ${parameter} and computer picked ${computerMove}.\n${result}\n\n wins: ${score.wins}\n Loses:  ${score.losses}\nTies: ${score.ties}\n Total Attempts: ${score.total}`);
        Result();
    }
    
    
    