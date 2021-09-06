FROM debian:testing-slim

RUN apt-get -qq update
RUN apt-get install -y --no-install-recommends \
      software-properties-common \ 
      python2 \
      build-essential nodejs npm gyp libcurl4-openssl-dev pkg-config

RUN rm -fr /var/lib/apt /var/cache/apt

ADD . /opt/somhunter

RUN sh -c 'cd /opt/somhunter && rm -fr .git node_modules build logs/* vbs-log/* media Dockerfile'

RUN echo "alias python=python2" >> ~/.bashrc 

RUN npm cache clean --force

# Create `data/v3c1_w2vv` symlink 
RUN ln -s '/mlcv/WorkingSpace/Personals/vuquang/v3c1/' '/opt/somhunter/data/v3c1_w2vv'
# Create `public/thumbs_v3c1` symlink  
RUN ln -s '/mlcv/WorkingSpace/Personals/vuquang/v3c1/thumbs' '/opt/somhunter/public/thumbs_v3c1'

RUN sh -c 'cd /opt/somhunter && npm install --unsafe-perm'

EXPOSE 8080
CMD sh -c 'cd /opt/somhunter && npm run start'
