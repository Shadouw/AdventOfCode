#include <iostream>
#include <map>
#include <string>
#include <vector>

#include <stringtovector.h>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const string inputTestdata = {
    "rn=1,cm-,qp=3,cm=2,qp-,pc=4,ot=9,ab=5,pc-,pc=6,ot=7"
};

const string inputData = {
    "rsndmp=6,ksc=4,vrgp=5,kj=2,zcjb-,qvgk-,tf-,vdvfgd-,rc-,jp=9,ksd-,jtt-,nf-,mrpp-,mn=9,fxf=7,km-,dj=8,klr=5,nxd=8,znm=2,qxlr-,vkt-,bnkzs=3,xtx=8,zd-,qcrjf=1,rlj-,hzzg=5,hm-,dnm=4,pvv=8,tglkn-,lp-,pk-,xtbnqk=1,mp=1,gjv=3,tvx-,lbvz-,trm=4,vbd-,qtc=8,clxl=1,nnsd-,zsz=7,gc=5,tnhlz=7,lvpk=6,vbrpq-,mkxd=6,chl-,sf=9,tnng=4,bx=1,gpr=5,cnvrmv-,nl-,mt-,qd-,rnb-,zqp-,zmx-,xl-,vhz=8,bqz=5,zmx=2,mv-,jmq-,dkx=7,zsqkmv=9,txv-,cnvrmv-,bqz=9,nhb=3,msv-,rmg=4,br=7,xdxg-,lpj=5,gbpn=2,vmq=8,jr=3,nf-,szm-,fbhhj=9,qppqr=8,rxrfs-,mgc-,gtgp=3,xpn-,lg-,cxkh=8,sl-,mv=5,tjr-,xsvx=6,kpzv=2,hxq-,cnn-,ss=3,rl=6,qlt=1,vbrpq=2,cx=4,vxk=8,rqz=4,pqrpll=7,ll=8,vlp-,fnxpm=3,rmg-,gtgp-,kslzd-,lbk-,pz-,lxs-,znglr-,fqn-,tvx-,kq-,hpl-,jkbjj=4,cpg=6,sscq=8,zgdz-,kgvc=7,llxln-,vbg=8,kj=6,fcf=5,pnf=9,fqk-,gktj=6,sqs-,dkx=5,jh-,tjr-,lvpk=3,vl-,ztzj-,tcn-,dnr=1,qmg-,jzrm-,tvvj-,cx-,cqq=6,vbrpq=2,gtgp=6,hpl-,ksn-,smb-,kcxs=2,qvn=3,sxj-,fzb-,br-,kp-,qxjcc-,rl-,hd=3,vkt=1,ht=3,qmtb=2,lts-,khkk-,th-,ghcq=9,trm-,jp=5,qs=5,nz=3,cdcx-,bf=7,bnkzs-,cnvrmv=4,zvbb-,hs=6,qcrjf-,rpqdq=3,rqz-,hjh=5,dcqgb-,mrpp-,lg=4,tcn=2,vt=9,dcgz=1,dvk-,vdgsj-,tvvj-,sf-,pl=5,skhhqs=3,rt-,vds-,js=1,fs-,mgc-,hcl=5,sgk-,gfg=2,fs=5,rbf-,dfj-,bf-,zph-,sq-,ptd=5,khkk=9,rr-,ms-,clxl=5,nhb=7,kf=1,cdcx=9,gmgm-,cqq=8,kc-,hj=3,rbf-,snp-,hxq-,cnvrmv-,st-,mm=6,zsf=2,ng-,pnf-,nf=2,xtbnqk=5,skhhqs=3,zt=6,zc=3,gvzmzc-,zc-,bkxssv-,sjp=2,dvsdzt=8,nf=3,jkbjj-,hg-,cpg-,tcjq-,bcx=3,chd=8,chl-,cnn=1,rl=3,qc=4,gqjz-,th-,vhz-,mn=4,smm=8,xgx=1,kp=4,hj-,tv-,rnb-,jvc-,tq-,pd-,zt-,gdl-,sxj=4,kll-,dv-,tp=1,kpzv-,kp=1,sb=4,nn=4,lkvsn-,dkx-,xn=1,gdl=6,kb=9,mm=4,xlmt-,kq-,frp-,jfkxtz=2,klr=4,bkxssv-,zgqghd=2,gqjz=3,smpc-,fvmq=5,jtt=8,rb-,sd=2,fvq-,qvn-,dd=9,jh=1,nhb=2,jntfg-,blnp=8,fvq=2,fzvf=5,ktx=6,zcjb=9,lfbd=8,pl=5,mbp-,lx-,gs-,hg=2,ssv=1,rmg=3,mrpp-,xtx-,hcl-,jvc=7,gb-,sph-,spl-,vhz-,gth=8,qhcxql=3,bvpm-,vxk-,bxr=4,vkt=8,spl=7,tvn-,tx=7,fhk=1,fb=1,bxr-,kfh=5,rb=7,bhmxb-,rtxv=8,vbd-,rbf-,smpc-,fhk=4,kps-,sg=5,zn-,tl=8,rnsn-,zh-,jg-,tlp-,sq-,bfh-,nld=5,hzzg-,kll-,nqbnhp=3,pl=2,rpqdq=2,ld=8,ccr-,qfsn-,pqdzh-,pjr-,nv-,fqq-,smb-,lvpk-,ssv=6,xlmt-,cs-,hxq-,nfp-,znglr-,mv=6,llxln=9,xfp-,jg=6,vz-,bk-,rxrfs-,xtx=4,hqvn=9,rprqz=7,ng-,tcjq-,nz=2,tdrb=3,qppqr-,pkz=9,mx=1,spl=7,khv=9,lc-,nf-,hcl=1,zlbh-,jt-,xfp=3,kb-,lnbn-,trqh=2,rtmrb=7,bsbmk=2,tglkn-,bvgcvj=3,mv=2,tb-,tj-,rrbm=2,gqjz-,bx-,jx-,qmtb=7,bhmxb-,mr=4,nn-,djsm=8,ls-,lczc-,sxh=4,cxbk-,vsn-,nh=6,lp=5,fkrqkk=2,chl=9,fcqp=4,tvn=2,vdh-,nh=1,gzqzr-,bx-,mt=3,fqq-,gfv-,clxl-,zdhl-,rtxv-,jt-,hjh-,kmnxl-,tv=5,jzrm-,pnf-,lc-,bgf-,tx=2,zhqd-,nmmg-,qxm-,vhz=1,qhmf=7,rpp-,rv-,dg=4,ms=4,sgk=1,vsn-,nsl-,df=9,ss-,jr=3,th=9,tz=5,fbhhj=8,kj-,nlgl=8,ss-,cp-,fzvf=2,kfh=9,hkq=4,tzk=4,vrgp=6,sn-,kcvbtr=6,vjr-,fvq-,bsbmk=4,qnqs-,bz=8,jsxn=9,mn=1,kzh=9,dkx-,gjv-,lfbd=2,lb-,ksc=1,rrdn-,zvbb=6,tcjq-,qvn=4,rnb=5,hrvqh-,zcpd-,gc=6,tglkn=2,msv=9,zp-,hzzg-,gvzmzc=5,mr-,szm=4,jn=4,df=2,kh=1,ckx=3,rv=4,xgx=5,bkvxr-,qkn=1,gbpn=4,fgnpl-,ztzj-,sph=8,ghm=1,lbk=4,kqh=2,gs-,df=2,gr=6,kqh-,pnf=1,tcn-,hs-,xnr-,mmnh=1,sscq-,kcvbtr-,dd-,chl-,xn=5,xr-,dg=7,sv=7,tdrb=2,psd-,sqs=7,hrhgpg=4,vrgmfz=3,fzvf-,qhsj=6,tv-,bxr=7,pl-,lfbd-,cdv-,rprqz=2,llxln-,gvg=6,bj-,gvg=3,krt-,gfv-,vht=9,ghm-,rptz=4,mx=8,zsz-,thmtr=7,cjgpm=7,jzxp-,mp-,mt=4,cmjvr-,nl=7,nf-,gfg=7,vbln=4,zsz-,tjr=7,gx=5,dnr-,xlmt-,bgf-,dv-,rl=2,vgsk-,vpc-,kll=6,xmd=3,ld-,tjr=2,tdrb-,vxk=3,gzp-,hhd-,ls-,xdxg-,lzr=2,cbs=7,gb=9,hj-,zsf-,gr-,kps=2,ktx=6,gx=9,jl=4,ppzh=7,bgf=1,jfkxtz=1,nqbnhp-,dd-,pnf-,lxs-,cjgpm=3,dl=2,vds-,krgqlg=6,rnb=8,nfp=7,jx=2,mjbmkg=5,lnbn-,qhsj-,gvzmzc-,rv-,mt=2,rnsn-,pl-,gfg-,lnx-,kb-,tmj-,vmq=6,dv-,lc-,ztzj=2,rvsv-,cdcx=8,jr=1,lhsr-,gr=3,bnkzs-,hm=8,fzvf=1,bgf-,fqq-,vz-,cx-,ll=4,sl-,sqs-,vbg-,tn=8,lx=5,jsxn-,mx-,nhb-,krv-,zcpd-,snp-,vmq-,md-,br-,dl=3,cxbk-,bgf=1,tvx-,ckx-,msv-,zcpd-,vds-,pk=2,chd=9,knvd-,fvmq=9,cdcx=6,qc-,tdg=8,tbm-,bhmxb-,tx-,fhk=6,gdl=5,cdcx-,ssv-,mm=6,kp=7,fdp-,hpl=9,szm-,bqz=7,qtc-,kn=1,jrpd-,vhz=9,cdv-,vlrh-,kh=4,gc=9,qhcxql-,bcx=8,fptsb=4,trqh-,fgr-,fnj=5,cqq-,blnp-,rtxv-,rsndmp=9,hzzg-,lnx=4,tl-,bv=8,jtt-,dkx-,zp=1,hm-,fb=7,qlt-,bk-,llxln=7,vj-,ccr=4,kn-,lts-,zcjb=3,gr-,bh=3,ksn-,jmq-,pl-,bcx-,vdvfgd-,vhz-,mk=8,lml-,vrgp-,krgqlg=6,pqrpll-,zcpd-,txv-,xhq-,klr-,zvbb=2,qtc=9,jg=4,dnr=6,rrdn=7,tdg-,kx=2,zsqkmv=9,hrhgpg-,tj=9,zk=5,lskzn-,rsndmp-,vdgsj=2,txv-,vd=2,rqz=1,nnsd-,jvc-,mpg=7,qxm-,flp=2,lpbkh-,vd-,ppq-,qxm-,lv-,lb-,ghm=9,nlgl=8,bc-,qhmf-,djfsp-,fsm=2,ls-,tn=1,qvn-,kgvc-,qmg-,djsm-,kx=8,sl-,qcfgk=9,nhb=7,ttv-,cmjvr-,rtxv-,lc=2,pp=4,bh-,ng-,kbnt=8,jg-,nlgl=7,vj-,tjr-,qqp=9,gs-,nl=1,nsl=2,sxj-,nf=8,xhq-,tnhlz=6,smb-,hjh=5,gpps-,tznz=6,lvpk-,zn-,bxr=9,llxln-,jkbjj=4,vt=4,zcjb=6,qxlr-,mx-,rc=7,tjr-,fkrqkk-,mk=1,lfbd-,ptd=9,gs-,gvz=8,dcgz-,nlgl-,zfp=4,zlbh=8,hhh-,jx=3,tjr=8,tf-,dfj=7,snp-,mq-,cx=4,smpc=6,gx-,hplkm-,kslzd=2,zbhkq=7,bfh-,zlbh-,qmk=3,mx=6,zsqkmv=5,zd=8,lpbkh=4,jlc=5,dn=7,gzp-,bz-,zkr-,fzb-,ffq=9,zh=5,fqn-,xsvx-,xtx-,rlcn-,dvsdzt-,llxln=1,gtgt-,fb=3,rsndmp-,kbh=2,jvc=3,kf=2,vxk=5,hzzg=4,ls=4,bt=3,llxln-,sv=2,pz-,zd-,mq-,njv=7,nf-,tdg=1,mt-,hxj=2,hcq=4,xpn-,rqz=4,gpps=5,qc=1,clxl-,zlbh-,hcl-,zcjb-,jbf=3,cbmm=3,jp-,vds-,zh=8,mxk=3,qs-,xlmt=4,bz-,vds-,zkr-,fqq-,ksn-,kgvc=8,vkt-,lczc=1,pqdzh-,ss=9,rr-,mhc=2,ghm=1,vjc=3,bvpm-,krgqlg-,kp-,xsvx-,svzft-,zsqkmv=8,hg-,ckx-,qc-,khv-,sscq=4,xkjv-,spl=5,lvpk=7,pvv-,vbd=3,nh-,df-,xkjv-,pqdzh=7,qhmf-,jl-,zsqkmv-,td=3,zgqghd-,chl-,hpl=5,cs=9,bvgcvj=7,jl-,lxs=1,cp-,gr-,lfzc-,tdrb-,cdv=4,sf-,ksd=7,qlqq=1,js-,znglr-,qhgkfk=8,skhhqs=1,tch=7,kb=4,qd=3,pkz=3,vpc-,dg=5,dvsdzt=5,mp=8,mxk=7,mrpp-,trm=9,gh=6,sttj=2,kfh=8,vpc-,sm=7,nl-,mp-,rxrfs=5,kzh-,fhk-,gfg=6,mkxd-,ghcq=1,nvc-,tx=3,bkvxr=1,vht-,lskzn-,dj=3,tz=3,xnvx=4,xnvx=1,cp=5,sn=2,bnvgm-,vdl-,js=1,bgf=6,vrq-,hxj-,tnhlz-,kll-,kvshp=3,qqp=6,tjr-,bgf=3,qvn-,jkbjj-,sscq-,mq-,hh-,bz-,xth-,nvc-,bvpm=6,mt-,smpc=7,qhcxql=1,fqq=7,fdp=7,qmtb=3,ksc=1,tmj-,kps=8,zsf-,lnx-,ctqb=8,qcrjf-,lpj=6,thmtr-,hjh-,xnvx=7,nh=4,ksn-,gfg=7,txv-,bz=5,khkk-,kfh=7,lvpk=3,jh-,tl=5,xlmt=9,hrhgpg-,ccr=8,trqh=5,tmj=1,qxm=3,dg-,kf-,mhc-,qxlr-,kb=1,fzb=9,fmk-,hjh-,hm-,tvn-,lc-,kll-,hxj-,cjgpm-,zdhl=4,zsqkmv-,cn-,kgvc-,sqs-,fnxpm=6,vdgsj-,gvzmzc-,lpcrt-,svb=6,krt-,zqp-,vjr=5,dvk-,chd-,sb=8,sqs-,bzv-,flxh-,tcjq=1,vd=4,vl-,th=6,vrgp=7,hzzg=2,rvsv=5,fzb=9,ldn=9,spl=4,kc=6,bfh=2,vgsk=1,pbnn=6,llxln=6,znm-,hcq=9,zb=4,kmnxl-,pnf-,kc=9,vlrh-,hpl=4,kps=7,gjv-,sqs=3,hmzm=4,pnjdp-,vn=1,rt-,psd=1,cxbk=9,dcgz-,smb=8,fzvf=6,njv-,ng-,kcxs-,tn-,dg=7,km=5,ghcq-,rrdn=6,zc=7,tj=9,fqq-,hmzm=6,ksc-,xtx-,gvzmzc-,bz-,zph=3,vrgp-,lvpk-,zkr=2,lxpgxq-,gzqzr-,kcxs=4,cxkh=3,sq-,lts-,cpg-,flxh-,fp-,hg-,qppqr=8,df-,gpr=2,vlrh-,ptd=2,qxjcc-,dg-,qcrjf-,dj-,pf=4,ztz=2,sm=9,cn-,dcqgb=4,th-,xsfs-,hkq-,gvzmzc=1,nfp-,fhk=1,lfzc=4,nhq-,bkvxr-,tv=1,qnqs-,bxr-,sf-,gtgt=5,rvsv=8,lbvz-,ll=3,gvg=9,chl=7,krt-,jx-,vrq-,fcf=3,hxq-,sv-,ksc=3,fcf-,zk-,sn-,nlgl=5,tjr-,fnj=3,kpzv-,vd-,rpp-,mpg-,hm=6,xpn-,pnf-,pf=9,lfbd-,lk=6,kpzv=4,lxs=2,tlp=8,zc=3,mn-,hcq-,mvs-,qqp=9,znglr=5,rrdn=7,zcpd-,vz-,nhb=2,st-,ld=8,jg=6,jtdj-,lc-,jtdj-,zd-,kbnt=5,nqbnhp=7,msv=8,lpbkh=4,cs-,vl-,vhz-,hkq-,hd=7,dl=9,vrgp-,flxh-,fgr=9,vbrpq-,jqh=5,rlcn-,klf-,tnng-,ms-,xnvx-,lczc-,ll=2,kvshp=8,bf-,lkvsn-,xmd=5,gzp-,ztzj=3,fdb-,gs=8,znglr=4,tf-,kf=2,xnvx-,lfbd-,vd=7,xkjv-,hmzm=2,xfp-,ssv-,zbhkq-,lc-,sscq=7,jl-,gfg=2,zgqghd=5,lnbn-,fdb=7,hlzk-,zdhl-,cn-,kmnxl-,zvbb=7,xtx-,kslzd-,jmq-,fkrqkk-,gjv=8,sg-,qs-,fqq-,lfzc-,qs=7,bgf-,kn=9,gvzmzc-,qvn=5,pk-,hkq-,fb-,zmg=6,nvc-,lnx-,bvpm=8,lxpgxq=3,jmq=8,jd=1,lxpgxq-,fs=3,kq=2,fcf=1,lpj=2,rnsn=4,dj-,kf-,xn=7,rnb-,gjv-,rprqz=7,nfp-,lvpk=4,vht-,tdg=4,vbd-,zbhkq=6,st=4,nptvm-,kmnxl-,rqz=4,cxbk=8,dnm=9,qnqs=4,cs=8,nl-,vbg=7,nv=1,bgf-,hgndd=1,mhc-,td=2,fnj-,flxh=5,qvn=9,jg-,zcjb-,gvzmzc=8,km=5,vbd=8,rr=9,msv=2,vdl-,xll=5,rprqz-,gh-,zd=8,fsm-,bxr-,bhmxb=1,nfp-,qxm=8,ptd=5,gtvr-,zgqghd-,jd=1,fzb=9,kxz=9,skhhqs-,gtgp=6,gtgp=3,ldn=8,sxj=3,trqh=2,sscq=7,hmzm=3,nld-,zn=5,tch-,gpps=8,jsxn=1,hjh=4,lpcrt=9,tcjq=2,fzvf=6,cbs-,jqh=8,vdl=6,svb-,kx=4,pnf=7,lph=7,qppqr-,fcf-,kp-,pnq=6,mt=4,gjv=6,khv-,zsz-,vpc-,qhgkfk-,mx-,th-,rtmrb-,ppzh-,tch=7,cp-,zbhkq=6,fgr=1,gv=5,qppqr=2,vl-,jx-,fgd-,lczc=5,smm=7,kb=2,pbnn=6,ppq-,rpp-,tcn=3,krv=9,dxf=3,pd-,krv-,rv-,qxlr=4,hm=9,mm=2,tp=2,bhmxb-,kf=3,nmmg-,vdl-,zc=5,zdhl-,bgf=6,llxln=7,kx-,lskzn-,ctqb-,nqbnhp-,gc-,vlp=8,ss=3,bnvgm-,hhd-,vxk=8,kx=5,jkbjj-,cnn-,qhcxql-,bj=6,ktx-,ldn-,fbhhj-,gvz-,fzvf-,djfsp=8,lpj-,bt=4,gvg-,rmg-,ntvb=9,cs-,ksn-,flp-,qtc-,vt=6,zlbh-,ppq=8,hs-,fmk-,gfv-,jbf-,tvvj=4,dnm-,fbhhj=4,mpg=3,hhd-,qcfgk=3,dnr=7,hmzm-,qcfgk-,djsm=1,bzv-,jsxn-,gpr=4,sq=1,fb=5,bxr-,kx=5,mv-,lpbkh-,jtt-,klr=9,fzb=7,dv-,rmg-,zdhl=1,gt-,bxr-,kll=4,hplkm=6,vj=6,mpg-,jg-,sf-,xn-,vrq=5,zbhkq=3,mx-,ccr-,js=1,svzft=3,vgsk-,kr=7,lg-,svb-,vlp=6,tnng=8,fgr=3,qlqq-,lfbd=8,ld-,snp=2,jmq-,mx=9,fcqp-,kf=7,lvpk-,fsm=6,tmj=1,pv-,jl=2,hhd=9,krgqlg-,cjgpm=1,lk-,kslzd-,bhmxb-,rxrfs=4,dnm=5,xnr-,nn-,sph-,kcxs=6,rlj-,dcgz=6,kbnt=3,bk-,jd=8,sf=7,mjbmkg-,lhsr=1,cdv-,klr=5,rbf=7,hrhgpg-,jd=9,kcxs-,vjc=3,bqz=6,qc=1,lczc-,lph-,kr-,skhhqs=7,rrbm=6,kf-,hh=1,vsn=7,tzk=2,tcjq=7,tl-,lts=4,dfj=1,gqjz-,fgd-,rc-,bqz-,vqb-,pf=3,gvg=1,hxq=9,gv=7,ss=7,pd-,tl=3,bkxssv=7,fkrqkk-,hrvqh=1,lml-,gpps=6,fptsb=6,sg-,bqz-,jn-,qmtb-,pnf=4,fcqp=8,nmmg=5,rr-,fb-,xtbnqk-,vdl-,rvh=9,hcq-,psd=7,xsvx-,vhz=2,gmgm-,kps=7,sv=4,zvbb-,bvpm=4,lkvsn-,xnr=3,vrq-,vjr=9,qcrjf=5,xddft-,khkk-,kr-,hhbxt=6,hpl=3,mg-,gdl-,xnr=9,jbf=5,rqz=9,rc=3,lhsr=6,gfv=2,vdh=2,lp=7,vrgmfz=8,hj-,vdr=7,ckx-,cp-,tbm=6,qvgk=5,tq=2,rl-,dxf-,fcf-,spl-,vdr-,rrdn=2,zcpd-,jx=2,lml-,mgc=2,pnjdp=3,dvsdzt=5,jzrm-,hhh-,szm-,lhsr-,qvn-,fnxpm=5,ctqb=5,mz=7,df-,xgx=3,xsfs-,vmq=5,xfp=4,lfbd=6,cnn-,gktj-,smb=9,vqb=5,hnkm-,zk-,qmtb-,sv-,lkvsn=9,kb-,xhq-,nhq-,trf=3,rnsn=2,mmnh-,kmnxl-,dv-,mrpp-,vj=2,jtdj=9,szm=4,chd-,kpzv-,kx-,qhmf-,fnj-,sd-,kx-,qxm=2,bxr-,sph-,tbm=6,xdxg-,bx=6,jtdj=7,fxf-,trf-,bsbmk-,vbqfsv-,nnsd-,nptvm=6,kq=8,hs=5,lts-,zqp=6,lxpgxq=8,gt-,bkvxr-,pnf=6,lczc=1,tjr=4,pbnn-,tdrb=2,tdg-,vztrlg=8,tnhlz-,zb=5,xnvx-,tvn=2,xfp=9,dv-,mxk=3,lk=4,sm-,tvn-,kbnt-,kcxs-,flxh-,ms-,ssv-,krv=1,tnng=2,mmnh=2,tvx-,xtbnqk=5,gbpn-,qr=6,cpg-,fxf-,jtt-,tch=4,ntvb=8,dkx=4,rprqz=8,chl-,fhk-,gth-,tmj=9,vpc-,zgqghd=4,nmmg=3,jr-,sgk-,cpg=2,qd=8,gvg-,vt-,gmgm=4,vbrpq=2,cx-,vlrh=7,kj-,nvc=2,nz=1,vgsk=6,bzv=7,kx-,qmtb-,pl-,th-,nlgl=1,krv-,zgqghd=4,lv=3,bv-,nn=8,smb-,tdrb=5,fhk-,ztz-,frp-,pjr-,xsvx-,mmnh=7,xsfs-,fxf=7,gs-,zk-,mn=3,spl-,qmg-,szm=9,psd-,ll-,cs-,nh=5,xr-,hcq-,njv-,mg-,jzrm-,llxln=8,trm-,svb=2,ksd-,zcpd-,gjv=5,ccr=5,bv=8,zsz=9,blnp-,krgqlg=9,tnhlz-,kcvbtr-,hzzg-,rlj-,zfp=4,nld-,kgvc-,gv-,vdvfgd=8,jbf-,rr=1,hrhgpg=1,hzzg-,fxf=7,hhd=6,hkq=6,sf-,trm-,bkvxr=7,tj-,tnng=7,qvgk-,lg=6,ksc=3,krv-,nptvm-,qhcxql-,klr=3,vrq-,fcqp=6,rsndmp=4,nfp-,hd=8,hd=3,lczc-,snp-,cbs-,hgndd-,ccr-,fgr=8,lzr-,zk-,bv-,sgk=4,bfh=1,ztz-,km=2,qmg-,jd=7,djsm-,fgr=4,fgr-,gzqzr-,qmg=8,ptd-,sph=8,smpc-,bvgcvj-,blnp=5,mxk=1,vlrh-,cpg=8,tdg-,fb-,hcl-,nv=9,vlp=4,gvz=6,kbnt=6,mxk-,hm=8,tj-,bc-,vbqfsv-,kq=6,fdp-,bk-,sf=2,zsz-,pd-,nn=1,xsvx=2,pp=7,bz-,sscq=4,jd=4,jf-,sn-,zdhl-,hxj=6,nsl=7,gjv=5,lx=7,gtgp=4,thmtr=4,tnng-,ppq-,kb=4,kps=9,qcfgk-,qxlr=9,kf-,vd=8,xnvx-,dxf-,mvs=3,rptz=5,rxrfs-,zd=7,jn-,jkbjj-,tznz-,rpqdq-,blnp=9,cnvrmv=3,dv-,rtmrb=3,xn=8,zcpd=7,ghm-,lxpgxq=3,xll-,fdp=1,gzp-,hq-,gc-,rxrfs-,dg=7,zc-,gzqzr=6,tvn-,xl=1,zlbh-,hnkm=6,gb-,gs-,lnbn=5,jr-,skhhqs-,cn=9,mg-,ffq-,vlrh=3,gktj-,sl=5,xnvx=4,trqh-,lfbd-,qcfgk=3,ms-,vdh-,pz-,bfh=1,bk-,tfghz=6,lnbn-,dl-,kzh-,vl-,zt=3,dcgz=2,vdgsj=4,cbs=9,md=1,zgdz-,vkt=6,zfp-,jx-,mn=9,bfh-,sq=9,qkn=2,pkz=2,qb-,kn-,zb=5,kmnxl=6,rpp=7,vt=8,rprqz=7,nnsd-,sq=1,frp=7,gbpn-,vjr=9,cxkh=2,fnj=5,knvd-,vsn-,lvpk=8,hhd=8,fgnpl-,gmgm=3,hqvn-,gzqzr-,vbg-,jsxn-,zmg=9,qb=9,trqh=4,cx=7,szm-,hlpc=2,lxs-,vqb-,fzb-,mm=4,pbnn=6,kfh-,spl-,jtdj-,sv-,vrgp=1,bt-,bkxssv-,pqdzh=8,trqh=9,mjbmkg=6,bkj=5,ctqb=2,cxbk-,trm-,vztrlg=3,sq-,jn=1,zqp=9,rprqz=3,tf=3,cpg=1,vdh=9,qppqr=6,kmnxl=1,sxh=7,ccr-,zk-,qmg=1,vpc=1,td=8,fnj=5,bkvxr-,zt-,bf-,kpzv=8,hrvqh=4,qppqr=5,cp-,tznz-,qr-,bc=7,bh-,df-,bf=8,pnq-,vbg-,jzrm=9,br=5,qhgkfk-,vj=1,tznz=8,jlc-,jg=4,nsl-,hnkm=3,gr=7,kcvbtr-,vl=5,zhqd-,bqz-,fzb-,fkrqkk-,sph-,lc-,bsbmk-,vqb=7,xsvx=3,xl=5,vsn=1,lm-,sl-,ss=7,dj=3,qlt=3,js=4,hhbxt-,vbd=8,sn=2,gx=3,hh-,kxz-,jd-,fqn=6,qhgkfk-,fgnpl-,bt=4,vds-,vj-,lnbn-,mv-,qd=9,hlm-,khkk-,lts=5,fcf=8,qkn-,ppzh=5,qcfgk=1,rv=8,gth=1,nz-,qvgk-,hd-,jtt=7,nqbnhp-,gktj-,mgc-,gv=4,fcsx=2,pf-,fzb-,xfp=7,zvbb-,kx=4,bnkzs=3,gpr=6,vpc-,js=6,vjr-,hlm=4,kfh=3,hh=8,fhk-,lbk-,tvx=2,nnsd=3,tnng-,kgvc-,dfj-,zcjb=1,gvg-,chl=6,dkx-,gfv-,ng=8,ld=5,trqh=6,js=3,fnj-,kp-,zmg=7,rsndmp=9,hrvqh-,kbh-,jzrm-,pbnn-,rptz-,zhqd=3,qhsj=7,fhk=2,hhh=9,fmk-,sgk=6,tmj=5,qd=8,hh=1,ctqb=5,gktj=1,sb-,cdv=9,xxl-,ccm-,sjp=3,kmnxl=1,jl-,qs=8,zjb=4,mbp=6,jp=8,lfbd=2,lczc-,jqh-,nb-,rr-,qtc-,psd=9,hzzg=7,kb-,vkt=7,bfh=4,hplkm=1,dl=8,sttj-,hnkm=5,lm=3,rpqdq=6,sttj-,kzh-,flp=9,vpc=7,lvpk=4,sttj-,nn=6,bcx=4,ld-,kpzv=4,lml-,sl=2,jr-,lb-,fgnpl=2,hpl-,tdg-,vztrlg=1,js-,td-,hzzg-,kp=7,cdv=2,vdgsj-,smm=1,frp-,gb=5,vrq=1,mpg-,lb-,vbg=6,rr=9,vjc=4,bx-,pnf-,ccm-,pf-,cxkh=6,kll=4,hg-,hzzg-,hhd=7,lm-,bcx=7,zmx=1,szm=6,rnb=5,msv=1,zqp=4,hhbxt=4,chd=4,krt=4,fqn=9,cn-,gfv-,dd-,lzr=3,lg=6,gv-,bnvgm-,lpj-,gbpn-,fdp-,hh-,xgx-,zk=1,gpps=7,hj-,qs-,smpc=6,zt-,zjb-,kbnt=4,lzr-,tj-,jtt=4,ckx-,jf-,zjb=9,dfj-,xlmt-,jx-,gkfk=8,vds-,ssv-,xll=3,gs=4,zph-,ktx=6,cxbk=6,kcxs=4,kqh=5,pnf-,tvx-,vqb=5,rl-,ttv-,fdb=4,vdl=8,jntfg=3,xxl=4,sv-,svb-,gvzmzc=9,ksd=8,xsfs=7,nz=1,qfsn-,fxf=3,pqdzh-,trf=8,fptsb=9,mkxd-,fzvf=6,dnr-,mhc-,tcjq-,tznz-,znm-,fcf=3,mz=4,xnvx-,ksc-,cs=4,nxd-,vxk-,tvvj-,pv-,rl-,tdrb-,qnqs-,kpzv-,rrbm=7,fsm-,flxh=6,zjb=9,kp-,tnng-,zd=7,dvsdzt=2,rptz-,lfbd-,fgd-,xnvx-,mq-,bsbmk-,fzb=5,gzqzr=3,kcxs=8,vdn=5,bsbmk=8,zgqghd=6,trqh=2,gfv-,znglr-,smm=6,qhsj=5,fnj-,zcpd-,vht=2,jr-,kq-,djfsp=7,dnm=9,khv=7,pbnn-,xtx=9,vsn-,vd-,ccr=1,kbh-,mxk-,xnvx=8,mr=6,cxkh=2,fgnpl=1,lml-,nv-,mv=9,krgqlg=4,ksn-,lm-,gc=8,sg-,ntvb=1,dkx-,pnjdp=4,jf-,fxf=5,vlp-,xsvx=4,vgsk-,spl-,tjr-,ppq=9,krgqlg-,qr-,jtdj-,sqs=1,nv-,dnm=5,cn-,nnsd=5,sxj-,pnjdp-,lm=6,qmg-,xtx=5,ccr-,qhmf-,bv=1,vkt-,cn=9,nf-,zb-,vqb-,qs=8,tvvj=5,ttv-,nh-,gvzmzc-,cn=3,ghm=7,ktx-,qb-,mhc-,vdl-,nld-,vbd-,gmgm=7,qhsj=1,rtmrb-,lk=7,lb=5,qr-,tmj=3,tznz=8,hh=2,zph-,jkbjj-,jg-,qxlr-,rvsv=6,sd-,xhq=8,krv-,mhc-,tfghz=2,kbh-,skhhqs=1,dcqgb-,flp-,rlj-,tb=6,ppq=2,znglr-,fgd=4,fcsx=7,pp=8,qlqq-,cdv-,krt=9,sscq=3,bh=6,qxm=3,nv-,hkq=1,nn=2,ghm=1,qxm=3,hpl=1,lpcrt=8,ng=4,zfp-,sph=6,zgdz-,lp=7,rsndmp-,bh-,hcl=3,nptvm-,qlt-,tvvj-,jd=7,lskzn=7,lczc=6,nfp=8,smm=7,fqn-,bnkzs=8,fkrqkk=5,tb-,cxkh=2,lc-,jqh=2,bzv-,bsbmk-,hlm-,dv-,rb=7,xtx=1,mxk-,gh=9,jh=6,fp=8,fzvf-,jzrm=4,flxh-,lfzc=8,fkrqkk-,fptsb-,cn-,ssv-,bkj=6,hrvqh-,bvpm=9,rnsn=7,smm=5,nf=2,xlmt=2,svzft-,sq=6,vlp-,ctqb-,thmtr-,msv=5,ppzh-,mvs=5,qcrjf-,zjb=4,tzk-,xtbnqk=7,ppzh=1,br=8,mp=7,cn-,qhgkfk-,dkx-,zh=9,hd=3,vds=7,rmg-,km=8,rt-,gbpn=1,nqbnhp=9,gth=8,fqk=9,zlbh-,sqs=8,cjgpm=9,hg-,sb=8,gzqzr=3,pl-,xth=7,rprqz=2,qvgk=2,zc-,kb-,bhmxb=2,sxh=3,hxj=6,cnn=5,nn-,qhcxql=6,zsz-,sv=8,zgqghd-,zcpd=9,bj=4,dj-,gv-,tznz=8,sv=5,rpp=4,qvn-,tdrb=8,sgk-,lczc=2,klf=6,glhkb=7,mvs=5,kxz-,fqq-,ttv=7,xsvx-,dd-,rl=1,vj-,fcsx=3,sqs-,bkj=9,md-,xth-,nxd=8,lxs=4,xl-,hh=4,bhmxb-,th-,dg=4,kslzd-,rvh=9,xtbnqk-,hs=7,zdhl-,mx-,gt=7,jfkxtz=6,fqq=2,cdcx-,cdv-,cs-,jtt=2,jzrm-,ll=5,kx-,vds=7,znglr=9,bt=8,bv=7,lts-,zd-,jbf=4,fhk=4,tnhlz=1,mt=8,hrvqh-,mv-,jf-,fp-,fnxpm-,ppzh=5,hhh=8,fcsx-,hs-,ztz=9,kb-,kq=9,mbp-,nsl=9,cx=7,rmg-,bkxssv=8,dj=7,lb=1,ccm=3,pv-,cnn-,qmg=1,fzvf=5,vmq-,vd-,njv-,fdp-,jd-,rprqz-,ppq-,zlbh=1,bnvgm-,mhc-,kqh=3,fcqp-,xdxg=9,tl-,hq=8,kll=8,tjr=3,js=3,qxjcc-,mq-,svb=3,ppq=8,lk=5,gbpn=3,khkk=7,nl-,skhhqs=5,cdv-,gpr=8,zkr=3,tmj=4,kq=3,gpr-,lv-,hcl-,cn=2,gzp=8,cbs=5,bnvgm-,gtvr-,zb-,fbhhj=3,fcqp-,pkz=6,fmk=5,jlc-,djfsp=6,lml-,qppqr-,mz=2,qmg=4,kbnt=9,zkr=3,gfg-,rlj=4,xpn-,rvsv-,kll=9,xl=7,vds=2,lhsr-,zk=4,fxf-,trm-,hcq=1,mq=2,lpj=6,vkt=3,qmtb=8,nf-,jx=1,bnkzs-,kcvbtr=9,lczc=4,jl=2,dnm=1,sb=3,hgndd-,lbk-,xtx=8,jn=4,fqk=8,qmg-,gvg=5,qmk-,ldn-,bkxssv-,xnr-,zdhl=2,fzb-,gvzmzc=9,rrbm=5,rvh=4,zkr=7,tz=7,cbmm-,vlp-,vxk-,vz=6,kr-,vrgp=5,lc=1,jkbjj-,pnq=8,vdr=9,rpqdq-,mg-,vgsk=2,fqq-,jl=7,rxrfs=7,qtc-,zcpd-,hq=9,hlm-,hlm=4,pp=4,znglr=7,fptsb=3,gth=4,kf-,nlgl-,glhkb=3,kx-,sg-,svb-,hrvqh=5,gx=3,zjb=9,vbrpq=2,sjp=8,svzft-,sqs=4,jzrm=4,kxz=4,rsndmp-,xhq=6,xsfs=2,qppqr-,hg-,jx-,qhsj=9,jh-,jh-,mkxd=6,xtbnqk-,lp=2,vjr-,trm-,vz=6,ld=5,mn-,bkvxr-,fgd=4,bt-,qxjcc=1,frp=9,tnhlz=5,tnng=6,zgdz-,rbf-,lph-,kn=1,hrvqh=5,trqh=2,fzvf-,hgndd=5,lph=8,tch-,nf-,qnqs=7,zjb-,tzk=1,lfbd=6,km-,rbf=7,dxf=2,kh=7,nf=8,rt=2,vn=2,df-,sl-,vj-,bsbmk=3,lts=9,sb-,qhcxql=7,lml-,qcrjf-,tvvj=1,hhd-,bz=1,ctqb-,djsm=4,sph-,mn=4,tn-,mjbmkg-,blnp=3,xtbnqk-,lxs=8,zh-,qfsn-,bj-,flp-,smpc-,gtgp-,gb=3,sl=7,gfg-,hs=5,pd=7,mn-,fcf=8,jg=2,mjbmkg=7,dkx-,bkvxr-,jn=6,smpc=6,zmg=7,vbrpq-,qs-,vdn=5,mxk-,qnqs=8,bh=7,nvc-,vbd-,vrgp=5,tdrb=3,zfp-,qhsj-,qqp-,pv-,mv-,xkjv=7,xtx=2,jx-,lxs=7,tzk-,tcn-,xlmt-,lhsr-,ht-,lph-,szm-,bvgcvj=4,gtgt=8,qhmf-,klr-,xsvx-,xll-,zqp-,rmg=2,llxln=8,tfghz-,trqh-,bk-,fp=4,ht-,lph=6,hmzm-,lfzc=3,xhq-,vz-,md-,gtvr=7,ll=7,gs-,bt-,sl-,qxjcc=7,snp-,gb-,kq=1,cn=6,gtgp=3,hd-,hm-,mjbmkg=1,qtc=8,sxj=8,fcsx=4,xxl=5,zk-,chd-,xsvx-,xr-,vmq-,gdl-,bf-,bj-,flxh-,dnr-,tznz=2,dg-,ntvb=6,lfzc-,xsfs-,lph=1,gzqzr=1,bvgcvj-,tmj-,lg-,rnb-,mvs-,cxkh=5,qvn=1,hs=7,qs-,rtmrb=5,zqp-,xll=3,zph-,vpc=6,fs=8,nz=2,szm=7,vqb-,qr-,hnkm-,rprqz=7,pjr-,lc=8,pf=5,cbs-,vdvfgd-,xll-,jn=5,tjr=7,lzr=2,vds-,hcq-,fzb=6,llxln-,vbqfsv-,xlmt=1,tq-,ppzh=4,vqb=2,sf=4,dfj-,lg=3,vht=4,svb-,sgk=5,klr=3,sq-,lk=9,rc-,lm=7,lph-,dxf=4,qfsn-,mz=1,kgvc-,mn=7,fgr-,trf=3,xlmt-,zp=5,pd=1,szm-,rr=3,pl=3,clxl=5,cbs=5,fdb=1,mvs-,vbln=5,rrbm=1,tf-,xpn=7,rqz-,tp=3,tfghz-,xnvx-,lph=1,bk=5,fdp=2,tvvj=9,jsxn-,qxjcc=5,vl=3,bqz-,kj=2,qppqr=6,dv=4,kb=9,nb=4,bnkzs=7,qr=3,nnsd-,xfp=7,vbln-,sb-,cpg=8,zvbb-,hs-,vlrh=5,mmnh=8,mbp-,pjr-,rnb-,ztzj=8,tx=2,qr-,mbp=3,fgnpl-,kc-,qhgkfk=2,zp=4,bxr-,dnm-,fhk-,vbln=7,pbnn-,gc-,cqq-,zjb-,lc=8,rvsv=6,rv=5,rxrfs=2,svb=5,vj=3,pk-,xn-,xtbnqk-,nlgl-,gpps-,lskzn-,bt=4,zbhkq=9,zmg=5,vqb-,jg-,hrhgpg-,vrq-,tn-,qb=6,zgdz=8,br=8,jr=1,tznz=5,nsl=9,kslzd=2,nsl=6,jfkxtz=9,jfkxtz-,gvz=1,bhmxb-,kbh=2,vn-,mxk-,bh=6,lbk-,rqz-,ccm=7,hcq=4,lxs-,fdp-,vl=9,xlmt=6,qd-,dnr-,xsvx-,xtx-,kx=3,sxh-,rt=8,ghcq-,frp=4,gs=6,nqbnhp-,dcqgb-,xsfs-,jtt-,vmq=3,sf=5,qcrjf-,hmzm-,vrgmfz-,kc=3,hxq-,lvpk-,gmgm-,cn=3,nmmg-,fdb=3,cx-,tl=5,cmjvr-,gdl-,rvh-,tj=9,lm=4,jqh-,jt=3,sv=6,nxd-,gfv-,ksc-,kll-,hlm-,trf-,qhcxql-,hm=3,lm-,fnxpm=7,tb=9,hplkm-,gmgm-,pnf-,clxl-,cqq=2,hcq=9,znm=5,fdb-,hpl-,zvbb=2,xgx=1,hcl=6,xdxg=2,sb=7,frp-,rrdn=9,pjr=3,znglr=8,ccm=8,cjgpm=8,km-,zsz-,mkxd-,gx=1,rxrfs-,nqbnhp=4,tcjq-,chl-,trf=9,pf=6,svzft=5,khkk=3,klf=8,mbp=7,hnkm=5,dv-,gbpn-,vz=4,ksc-,sttj-,qcfgk=4,fgd-,knvd-,hd-,jh-,kqh=5,ktx=8,lfzc-,trf=4,cdv-,zph-,hnkm=5,zmg-,vdn-,xn=7,pnq-,mjbmkg=7,sb=6,vjr-,zqp-,pjr=7,nptvm=7,sxh-,kc-,qxlr-,nhq=1,jlc=7,trm-,khv-,xlmt-,fqk=2,sttj-,hm=5,kxz-,tn=3,gvzmzc=7,zc-,gfg=4,fsm=5,hlzk=4,rl=6,lx=4,djsm-,rlcn=9,tvx-,hzzg-,jvc=9,dj=2,kqh-,lpj=8,dnm=3,vbd=9,glhkb-,dcqgb-,jt-,vdn-,gtgp=4,lbvz=9,st-,zqp=1,hjh-,sv-,pqrpll=7,hkq=8,xhq=6,tmj-,fcqp-,ttv=7,jp=1,hgndd=8,jvc-,qmtb-,psd-,nvc=7,lhsr=6,fnj-,gc-,mhc=1,cx=9,tcn=5,rl-,tj-,dkx-,jzxp=5,bz-,xnvx-,vdvfgd-,hh=5,dkx=5,kgvc=2,mjbmkg-,hlzk-,fqk-,rrdn-,br-,pp-,lc=3,qhmf=3,dkx=3,bnvgm-,zgqghd-,gkfk-,ckx=2,bnkzs=1,tb-,kbnt-,vbd-,fmk=4,xgx=1,snp=6,krgqlg-,nqbnhp-,xsfs-,lpj=3,rb=9,nb-,dn=9,zhqd=3,vdr-,ttv=9,kzh=7,hhbxt=6,zsf-,xfp=8,tzk=7,tn=4,vdn=9,gjv-,qmtb-,pl-,pp-,qfsn=7,cbmm-,fqn-,jrpd-,tbm=4,pqrpll=5,zsz-,zsz=8,lk=6,djfsp=9,nqbnhp=1,vjc-,qnqs-,zmg=4,fnj-,qcfgk-,jrpd=1,sg-,lv-,qlqq=3,rrbm-,kvshp-,thmtr=6,blnp=2,smb=1,jsxn-,rvh=1,tcn-,mn-,kvshp=9,pnq=8,ztzj=2,vztrlg-,ckx-,mbp=5,qfsn=1,tvn=6,nxd=6,td=2,bk-,mgc=5,bf-,cjgpm-,zhqd-,cpg-,df-,mpg=5,tz-,bvpm-,kj=2,fp-,fnj-,vlrh-,lhsr=2,hplkm-,bcx=4,gtvr=3,klr=3,hlpc=6,gtvr=1,tcjq-,tv=1,qlqq=1,rsndmp-,kps-,rnsn=9,hhbxt=7,zsqkmv=5,vrgp=6,vsn=3,cxbk=5,vrgmfz=2,zbhkq-,bz-,tz-,dnr-,nn-,tq-,nhb-,nnsd=3,dd=1,lbvz-,vlrh-,lk-,mgc=8,jbf=2,pnf-,krv-,chl=2,ghcq-,lc-,qc=2,jrpd-,dnr-,zsz=9,nqbnhp=9,bsbmk=1,lx=1,vd=3,kps=6,hpl-,bzv=3,cdv-,kh=4,dj-,krv=8,dnm-,trqh=7,bj=5,zp=8,qr-,jl-,bvgcvj-,mrpp=1,qhsj-,xdxg=3,gh=6,lczc-,fptsb-,gtgt-,pqrpll=3,smpc-,ghm-,sph=3,smm-,ssv=1,sl-,rrbm=1,trf=8,xpn=5,krt-,rt=7,thmtr=2,tch=6,vjr-,khv-,qhcxql-,vbg=1,kcvbtr=2,fnxpm=5,gzqzr=3,gzqzr=4,tfghz=3,lnx-,sm=2,fqq-,jvc=6,nqbnhp=5,dkx-,vt=4,lkvsn-,dfj=8,trf=3,ksc-,xnvx=1,km-,vdh=6,rt-,hhh-,fbhhj-,lpbkh=8,kc=7,qb-,gfg-,clxl-,rlcn=6,fgd-,hxq-,vztrlg-,hh=3,flxh-,jbf=1,vd-,klf=9,vdl-,jl=8,nmmg-,js=3,trm-,cbmm-,lbvz-,tjr-,dnr-,pf=2,kpzv-,fs=6,cbs=4,fgr-,thmtr=5,ng=8,gzqzr=5,zjb=8,nqbnhp-,vbln=8,mbp=8,gmgm=3,pqdzh=7,pd=8,ng-,kc-,djfsp-,qfsn-,smpc-,gfv=7,mgc-,tjr-,sl-,dd-,fhk-,nsl=3,bk-,qcrjf-,nmmg=7,vhz=8,kx=2,pl=4,klr-,zdhl=8,jt-,jbf-,vn-,pvv-,cnn=3,zsf=3,xth=9,cp-,gdl-,ptd-,pbnn=6,vn-,bk=3,pz-,jlc=7,zcjb-,cx-,zph=7,lx-,gr-,sn=2,dfj-,sm-,dj=1,kn=9,rptz-,znm=7,tnng=8,hm=2,mrpp-,hjh=9,hxj-,tmj=6,pv-,rv=5,smm=1,vbqfsv=6,znm=1,psd=6,llxln=9,pz-,gt=9,vlp=6,sv=8,vrgp=5,zhqd-,fzvf=4,mrpp=9,zfp=9,rsndmp-,cpg-,xtbnqk-,xpn-,rlj=6,nqbnhp-,trqh-,bt-,zgqghd=6,vmq-,lbvz=7,jx-,qc=8,fsm=3,vd-,vbrpq=8,vbd=7,nn-,gvg-,jtt-,sph-,ls-,kcvbtr-,spl-,hnkm-,cmjvr-,gb-,nvc-,vdn-,kslzd-,nmmg=6,zn=9,xl=2,chl=1,fgr=9,hnkm-,lb-,hd-,ghcq-,fcf-,tl-,pnq-,vpc-,dn=5,vkt-,nhq-,qfsn-,kb-,bhmxb-,qmg=2,gdl-,gx=2,kcxs=5,vd-,bfh-,ll-,xnvx-,khv=4,rptz=4,rpqdq=6,lc-,qkn=1,vxk-,bqz-,rl-,nb=6,ctqb=1,mv-,tdg=4,cp=3,krgqlg=5,ll=7,ctqb=2,nl=2,cxkh-,bfh=5,kb=2,hs=6,fgd-,gdl-,vds-,xl-,kxz-,qmtb=4,lm=5,bx=9,jl=3,vdgsj=6,bh-,zph=4,vdh-,gth=6,gzp=9,zgdz=6,hq=9,rlcn=9,xl=2,gtgp=9,gh-,kfh-,fvq=5,cp-,trqh=8,tvn=5,tznz=7,smpc=8,jqh-,qs=1,tv=7,tcn-,zkr=4,hs=2,gtvr=2,nlgl=1,lhsr-,tdrb=5,sn=9,trm=1,jqh=3,ppq=1,xpn=7,jmq-,pqdzh-,fcsx-,zvbb=9,dj-,bt-,qhmf-,lxs-,hzzg=1,gpps=8,hrvqh=9,nfp-,lp-,pl-,vn=5,krgqlg=2,trf=9,lfbd=8,pbnn=8,rprqz-,fqn-,nmmg=2,gx-,bkj=4,bj-,kbh=2,md=6,jrpd=2,smpc-,djsm-,qxlr-,tvvj-,gfv=8,chd-,jx-,vpc-,cdcx-,cs=9,sqs=5,pnq-,znm-,pvv=3,bh-,ctqb-,vds-,qvn=4,xdxg-,bv-,zb-,qhsj-,jl=9,nz=3,zmx=6,bv-,tglkn=3,rbf=5,tj-,pnf=6,qqp=1,qmk=5,pk-,njv-,jzrm-,kll=6,jsxn-,rtmrb=3,zqp=5,fsm=2,bvpm-,hpl-,rrbm=1,khkk-,xl=8,ntvb=1,hjh=5,ldn=1,js-,bf=9,gvz=1,bj=3,dnm=4,gvg-,rnsn-,tn=8,vxk=9,dl-,zhqd=2,txv=8,fptsb=6,bzv-,cdcx-,ghcq-,cnn=1,bqz=9,blnp=6,hgndd=1,xr-,nhb-,rb-,lml-,jh=8,krv-,cbmm-,sb-,gt-,qs-,znglr-,trm-,zgdz=4,ntvb=8,gjv=9,bxr=5,hrvqh=2,jlc-,rsndmp=4,vrgmfz-,kcxs=5,zmx-,xsfs=6,zgqghd-,dn=4,qxlr-,rc=7,lkvsn=3,mgc-,xtbnqk-,snp=5,jzxp-,znm=4,st-,kb-,zh-,rbf-,klr-,xdxg=6,zdhl-,bnvgm=3,nv=5,jbf-,rbf=4,zsqkmv-,bvgcvj-,sqs=6,tl=9,ht-,vbg=4,zsqkmv-,ntvb-,hhd=1,xlmt=8,dxf=4,tnng-,nnsd-,sxh=9,klr-,sjp-,nptvm-,tvn=8,sd=5,fdp-,ckx-,th=8,vbg=6,tz-,bv=2,hg=7,mr=7,qmk-,fgnpl=3,fxf-,sqs=3,ptd=3,zmx-,bx-,gpr=4,lml=3,ht=5,qd=3,lnbn=3,bx-,pnf=9,rc=9,xsfs-,xkjv-,sxh=6,tch=4,lv=4,ffq=5,zjb-,mjbmkg=9,qcfgk=3,pnq-,qhgkfk=6,tzk-,kslzd=1,sl-,sq=4,psd=4,knvd=1,vds=5,sq=7,gbpn-,fcf=6,snp=8,jtdj=9,sxh=7,cnvrmv-,qlt=8,cdcx=3,bgf-,vjc=9,hpl=5,fb=2,bt=1,mz-,gvz-,mr=7,ffq=3,mpg=8,nmmg-,zn=5,cxbk-,mm-,nvc=6,ssv-,mg=2,kzh-,bgf=1,mm-,nl-,kb=6,nz=1,lxs=6,jntfg=2,qnqs=4,ghcq=2,hrvqh=1,fs-,zh-,ll-,fdp-,rnb=2,zph-,jzrm-,znglr=2,rnsn=5,fnj-,mn-,bf-,xsvx-,kc=3,xsfs-,dn=4,tmj-,pkz=5,vlp=8,ztzj=2,tp=8,mgc=6,zh=1,gt=6,gpr-,hrhgpg-,jbf-,pvv=9,tx=3,pf=5,qb-,xhq=6,zkr-,skhhqs-,bk-,bkj-,ll=9,pqrpll-,krv=3"
};

class initialization {
public:
    initialization(const string _input)
        : input(_input)
    {
        auto posminus = input.find('-');
        if (string::npos == posminus) {
            vector<string> temp = stringtovector(input, '=');
            label = temp[0];
            focallength = stol(temp[1]);
        } else {
            label = input.substr(0, posminus);
            focallength = -1;
        }
    }

    long getHash(string s)
    {
        long hash = 0;
        for (auto c : s) {
            hash += c;
            hash *= 17;
            hash %= 256;
        }
        return hash;
    }

private:
    string input;
    string label;
    long focallength = -1;

    friend class LensLibrary;
};

class LensLibrary {
public:
    LensLibrary(const string& _input)
        : input(_input)
    {
        cout << "Size of Input: " << input.size() << endl;

        auto temp = stringtovector(input, ',');
        // Parse data
        for (auto elem : temp)
            initializationsequence.push_back(initialization(elem));
    }

    long getResultA()
    {
        long resultA = 0;
        for (auto i : initializationsequence)
            resultA += i.getHash(i.input);

        cout << "resultA: " << resultA << endl;
        return resultA;
    }

    long getResultB()
    {
        for (auto i : initializationsequence) {
            int hash = i.getHash(i.label);

            if (i.focallength > 0) {
                bool found = false;
                for (auto& m : focallengthmap[hash]) {
                    if (m.first == i.label) {
                        m.second = i.focallength;
                        found = true;
                        break;
                    }
                }
                if (!found)
                    focallengthmap[hash].push_back({ i.label, i.focallength });
            } else {
                for (auto m = focallengthmap[hash].begin(); m != focallengthmap[hash].end(); ++m) {
                    if (m->first == i.label) {
                        focallengthmap[hash].erase(m);
                        break;
                    }
                }
            }
        }

        long resultB = 0;
        for ( int box=0; box<256; ++box)
        {
            int j=0;
            for ( auto i : focallengthmap[box] )
            {
                resultB += (box+1) * ++j * i.second;
            }
        }

        cout << "resultB: " << resultB << endl;
        return resultB;
    }

private:
    const string input;
    vector<initialization> initializationsequence;
    map<int, vector<pair<string, long>>> focallengthmap;
};

TEST_CASE("Testdata")
{
    LensLibrary problemData(inputTestdata);
    REQUIRE(1320 == problemData.getResultA());
    REQUIRE(145 == problemData.getResultB());
}

TEST_CASE("LensLibrary")
{
    LensLibrary problemData(inputData);
    REQUIRE(503487 == problemData.getResultA());
    REQUIRE(261505 == problemData.getResultB());
}