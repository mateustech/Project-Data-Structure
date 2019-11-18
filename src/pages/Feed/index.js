import React, { useEffect, useState } from 'react';
import '../Feed/style.css';
import api from '../../services/api'


export default function Feed() {
  const [repos, setRepos] = useState([])

  async function loadRepositories() {
    const user = await localStorage.getItem('@username')
    const response = await api.get(`/users/${user}/repos`)
    setRepos(response.data)
  }
  useEffect(() => {
    loadRepositories()
  }, [])


  return (

    <div className="container">
      <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css"></link>
      <h1>Repositorios</h1>
      {repos.map(repo =>
        <div className="card">
          <div className="full_name">
            <p>{repo.full_name}</p>
          </div>
          <div className="status">
            <div className="stars">
              <p><i className="fa fa-star" /> {repo.stargazers_count}</p>
            </div>
            <div className="forks">
              <p><i className="fa fa-code" /> {repo.forks_count}</p>
            </div>
            <div className="watchers">
              <p><i className="fa fa-eye" /> {repo.watchers_count}</p>

            </div>
          </div>
        </div>
      )}
    </div>
  );
}
