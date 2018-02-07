#!/bin/bash



for i in {1..255}
do
dig -x 147.210.18.$i +short ;
done

