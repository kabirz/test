#!/bin/bash
for((i=0;i<72;++i))
do
	if [ ! -e CyanogenMod\?page\=$i ];then
		wget -c https://github.com/CyanogenMod?page=$i
		if [ "echo $?" != 0 ];then
		   exit -1	
	   fi
	fi
done

grep href=\"/CyanogenMod/ *  |awk '{print $3}'|grep CyanogenMod >new.log

sed -i -e 's/href/<project name/g' -e 's/$/ \/>/g' new.log

rm -fr Cyanog*
