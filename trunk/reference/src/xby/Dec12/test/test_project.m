clear all
% Compileraufruf
%nvmex -f nvmexopts_bb_double.bat mexUnitTestMain.cu -IC:\CUDA\include -LC:\CUDA\lib -lcudart
%nvmex -f nvmexopts_bb_double.bat mexUnitTestMain_cpu.cu -IC:\CUDA\include -LC:\CUDA\lib -lcudart

%mex mexUnitTestMain_cpu.c

a1 = 3*ones(100000,1);
a2 = a1;
%tic
%b1 = mexUnitTestMain_cpu(a1,1)
%toc
%tic
%b12 = mexUnitTestMain(a1,1)
%toc

tic
  b2=mexUnitTestMain_cpu(a1,a2,0)
toc
tic
b22 = mexUnitTestMain(a1,a2,0)
toc
%%%matrixMul
%%%%N < sqrt(mem/12)
%N = 4000
%A=ones(N,N);
%B = 1*ones(N,1);
%tic
%b3 = mexUnitTestMain_cpu(A,B,2);
%toc
%tic
%b32 = mexUnitTestMain(A,B,2);
%toc

