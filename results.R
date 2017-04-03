#!/usr/bin/env Rscript

png(file="resultats_mut_noD.png")

data <- read.csv("Lresultats.csv",header = FALSE)
data <- as.matrix(data)
data


A_init <- seq(0,50,10)
t <- seq(1,1500,100)


persp(A_init,t,data,theta=230,phi=15,xlab='[A]i',ylab='T',zlab='Nombre de bactéries',col="chartreuse1",expand=0.5,shade=0.8,ticktype="detailed")

dev.off()

png(file = "resultats_mut_noD-.png")
persp(A_init,t,data,theta=-230,phi=15,xlab='[A]i',ylab='T',zlab='Nombre de bactéries',col="chartreuse1",expand=0.5,shade=0.8,ticktype="detailed")
dev.off()
