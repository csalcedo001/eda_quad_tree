import cv2
import numpy
import matplotlib.pyplot as plt

n_img = "photo1.png"
img = cv2.imread(n_img);
img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
#plt.imshow(img)

altura  = img.shape[0]
ancho = img.shape[1]

f = open("matriz.txt", 'w')
f.write(str(altura))
f.write(" ")
f.write(str(ancho) + "\n")

for i in range(altura):
  for j in range(ancho):
    f.write(str(img[i][j][0]) + " ")
    f.write(str(img[i][j][1]) + " ")
    f.write(str(img[i][j][2]) + " ")
  f.write('\n')

f.close()

