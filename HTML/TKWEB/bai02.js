var index=0;

changeImg = function(){
    var imgs = ["/HTML/TKWEB/imges_02/1.png", "/HTML/TKWEB/imges_02/2.png","/HTML/TKWEB/imges_02/3.png","/HTML/TKWEB/imges_02/4.png","/HTML/TKWEB/imges_02/5.png"];
    document.getElementById("img").src = imgs[index];
    index++;
    if(index==imgs.length){
        index=0;
    }
}

setInterval(changeImg, 2000);