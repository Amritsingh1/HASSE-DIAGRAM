from tkinter import *
color = "white"


def create_circle(x, y, r, canvasName):
    x = float(x)-r
    y = float(y)-r
    x0 = x - r
    y0 = y - r
    x1 = x + r
    y1 = y + r
    return canvasName.create_oval(x0, y0, x1, y1, outline=color, width=2)


def drawedge(x1, y1, x2, y2, canva):
    x1 = float(x1)
    y2 = float(y2)
    x2 = float(x2)
    y1 = float(y1)
    canva.create_line(x1, y1, x2, y2, width=2, fill='white')


def drawnum(num, x, y, canva):
    canva.create_text(x, y, font=('Impact', -40), text=num, fill='white')


n = int(input())
# prflot (n)

coord = {}

adj = []

for i in range(n):
    a, b, c = input().split()

    subl = [a, b, c]

    coord[a] = [b, c]
    adj.append(subl)


e = int(input())


root = Tk()
root.title('HASSE DIAGRAM')

# bg="blue", height=250, width=300
root.geometry("1910x1070")
myCanvas = Canvas(root, bg="black", height=1070, width=1910)
myCanvas.pack()

for i in range(n):

    drawnum(adj[i][0], adj[i][1], adj[i][2], myCanvas)


for i in range(e):
    s = input()
    if(s != ""):
        a, b = s.split()
        if a == b:
            create_circle(coord[a][0], coord[a][1], 15, myCanvas)
        # prfloat(a,coord[a][0],b,coord[a][1],coord[b][0],coord[b][1])
        drawedge(coord[a][0], coord[a][1], coord[b][0], coord[b][1], myCanvas)
    else:
        break

root.mainloop()
