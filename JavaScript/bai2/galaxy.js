window.onload = function(){
    let images = document.querySelector(".thumb img");
    for(let im of images)
        im.onmousemove = function(){
            let d = document.getElementById("main");
            d.src = this.src;
        }
    let buttons = document.querySelector(".btn button");
    for(let b of buttons)
        b.onclick = function(){
            let c = this.getAttribute("rel");
            let d = document.getElementById("main");
            d.src = `/JavaScript/galaxys8/${c}_1.jpg`;
            for(let i=0; i<images.length; i++){
                images[i].src = `/JavaScript/galaxys8/${c}_${i+1}.jpg`
            }
        }
}