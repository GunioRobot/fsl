#!/bin/sh

subjdir=$1
nfibres=$2
fudge=$3
bi=$4
njumps=$5
sampleevery=$6
model=$7
slice=$8

slicezp=`${FSLDIR}/bin/zeropad $slice 4`

${FSLDIR}/bin/xfibres\
 --data=$subjdir/data_slice_$slicezp\
 --mask=$subjdir/nodif_brain_mask_slice_$slicezp\
 -b $subjdir/bvals -r $subjdir/bvecs\
 --forcedir --logdir=$subjdir.bedpostX/diff_slices/data_slice_$slicezp\
 --fudge=$fudge --nj=$njumps --bi=$bi --model=$model --nonlinear --se=$sampleevery --upe=24 --nfibres=$nfibres  > $subjdir.bedpostX/logs/log$slicezp  && echo Done

