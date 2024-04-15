function start()
{
    var setcolor = false;
    var msgcolor = "#ffffff";
    if (parseInt(msgcolor, 16) > 10000000)
    {
        setcolor = true;
    }
    for (let i = 0; i < document.getElementsByTagName("msg").length; i++)
    {
        document.getElementsByTagName("msg")[i].style.backgroundColor = msgcolor;
        if (setcolor)
        {
            document.getElementsByTagName("msg")[i].style.color = "#000";
        }
    }
    setInterval(update, 100)
}
function getRandomColor() {
    var letters = '0123456789ABCDEF';
    var color = '#';
    for (var i = 0; i < 6; i++) {
      color += letters[Math.floor(Math.random() * 16)];
    }
    return color;
  }
function update()
{

}