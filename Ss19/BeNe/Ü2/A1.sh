#! /bin/bash
  if ! [  $# -eq 1 ]
      then echo gebe ein Verzeichnis mit
  elif [ -d $1 ]
      then cd $1
        for file in {*.png,*.jpg}
          do
            if [ -e $file ]
              then
                if [ ! -d $( date -r $file "+%Y-%m" ) ]
                  then
                    mkdir $( date -r $file "+%Y-%m" )
                fi
                mv $file $( date -r $file "+%Y-%m" )
            fi
          done
  else
      echo kein Verzeichnis
  fi
