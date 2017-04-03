#!/usr/bin/env Rscript

pdf(file="resultats_10000.pdf")

data <- read.csv("resultats_10000.csv",header = FALSE)
data1 <- as.matrix(data)
data1

A_init <- seq(0,50,10)
t <- seq(1,1500,100)


persp(A_init,t,data1,theta=-160,phi=15,xlab='[A]i',ylab='T',zlab='Nombre de bactéries',col="lightgreen",expand=0.5,shade=0.8,ticktype="detailed")

dev.off()
