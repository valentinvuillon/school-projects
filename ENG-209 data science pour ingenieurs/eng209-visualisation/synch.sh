#!/usr/bin/env bash

logmsg() {
    echo "$(date +'%Y-%m-%d %H:%M:%S')] >>>>>> $*"
}

git_merge_to_master() {
    local -r upstream=${1:-null}

    logmsg "INFO:  merge ${upstream}/master to master"
    while ! git merge --no-edit -m "merge upstream" -s recursive -X ours ${upstream}/master; do
        logmsg "failed to merge ${upstream}, trying again in 5s"
        sleep 5
    done
}

git_add_remote() {
    local -r remote_git=${1:-null}
    while (( $(git remote -v|grep -Ec ${remote_git}' \(fetch\)')<1)); do
        if ! git remote add upstream ${remote_git}; then
            sleep 1;
        fi
    done
}

git_fetch_upstream() {
    local -r upstream=${1:-null}

    logmsg "INFO:  fetch from stream ${upstream}"
    while ! git fetch ${upstream}; do
        logmsg "failed to fetch ${upstream}, trying again in 5s"
        sleep 5 
    done
}

main() {
    set -euC
    local -r remote_git="https://renkulab.io/gitlab/eng209/eng209-visualisation.git"

    'unalias' -a

    export -f git_add_remote
    export -f git_fetch_upstream
    export -f git_merge_to_master
    export -f logmsg

    logmsg "INFO:  fetch from remote parent ${remote_git}"

    if (( $(git status --short|wc -l)>0 )); then
        git status
        logmsg "ERROR: repos contains uncommitted changes; 'git commit' or clean up your changes and try again."
        return 1
    fi

    if (( $(git status|grep -Ec '^On branch master')!=1 )); then
        logmsg "ERROR: you must be on tip of master branch, 'git checkout master' and try again."
        return 1
    fi

    if ! timeout -s 1 3 bash -c "git_add_remote ${remote_git}"; then
        logmsg "ERROR: cannot add ${remote_git}"
        return 1
    fi

    local -r remote_id=$(git remote -v|sed -En 's|(^[^ ]+) *'${remote_git}' \(fetch\)|\1|p')

    if [[ "${remote_id}"=="origin" ]]; then
	logmsg "ERROR: already on stream origin, use the 'git pull' command."
    	return 1
    fi

    if ! timeout -s 1 60 bash -c "git_fetch_upstream ${remote_id}"; then
        logmsg "ERROR: cannot fetch from ${remote_git}"
        return 1
    fi

    if ! timeout -s 1 60 bash -c "git_merge_to_master ${remote_id}"; then
        logmsg "ERROR: cannot merge ${remote_id}/master to master"
        return 1
    fi
}

main "${@}"
