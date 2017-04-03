#!/usr/bin/env Rscript

data <- read.csv("resultats.csv",header = TRUE)
data
A_init <- seq(0,50,10)
t <- seq(1,1500,100)
La <- c()
Sa <- c()

col1 <- rgb(1, 1, 0, 1)
col2 <- rgb(0, 1, 1, 1)

par(mfrow=c(3,2))
for (a in A_init)
{
  Lt <- c()
  St <- c()
  for ( i in 1:90)
  {
    if (data[i,3] == a)
    {
      Lt <- c(Lt, data[i,1])
      St <- c(St, data[i,2])
    }
  }
  plot(t,Lt,type='l',main=c("A_init",a),
       ylab="Nombre de bactéries",xlab="Fréquence du changement du milieu",
       ylim=c(0,100), xlim = c(0,1500),
       cex.main=0.9, cex.lab=0.8, cex.axis=0.7, mgp=c(2, 1, 0), col = col1)
  lines(t,St,type='l',col = col2)
  legend("topright", legend = c("L", "S"),
         lwd = 1, col = c(col1, col2))
}

par(mfrow=c(3,5))
for (ti in t)
{
  La <- c()
  Sa <- c()
  for ( i in 1:90)
  {
    if (data[i,4] == ti)
    {
      La <- c(La, data[i,1])
      Sa <- c(Sa, data[i,2])
    }
  }
  plot(A_init,La,type='l',main=c("T",ti),
       ylab="Nombre de bactéries",xlab="Concentration initiale en glucose",
       ylim=c(0,100),xlim = c(0,50), 
       cex.main=0.9, cex.lab=0.8, cex.axis=0.7, mgp=c(2, 1, 0), col = col1)
  lines(A_init,Sa,type='l',col = col2)
  legend("topright", legend = c("L", "S"),
         lwd = 1, col = c(col1, col2))
}
