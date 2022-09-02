import React, { useState } from "react";
import { Formik, Field } from "formik";

const Formulario = () => {
    const [formularioEnviado, setFormularioEnviado] = useState(false);
    return (
      <>
         <Formik
            initialValues={{
                nombre: '',
                correo: '',
                password: '',
                mensaje: ''
            }}
            validate={(valores) => {
              let errores = {};

                // Validacion nombre
                if(!valores.nombre){
                    errores.nombre = 'Required'
                } else if(!/^[a-zA-ZÀ-ÿ\s]{1,40}$/.test(valores.nombre)){
                    errores.nombre = 'El nombre solo puede contener letras y espacios' 
                }
                // Validacion correo
                if(!valores.correo){
                  errores.correo = 'Required'
                } else if(!/^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$/.test(valores.correo)){
                  errores.correo = 'El correo solo puede contener letras, números, puntos y guion bajo.' 
                }
                // Validacion password
                if (!valores.password) 
                  errores.password = "Required";
                else if (`${valores.password}`.length < 7)
                  errores.password = "La contraseña debe tener más de 7 caracteres";

                return errores;
            }}
            onSubmit={(valores,{resetForm}) => {
              resetForm();
              console.log('Formulario enviado');
              setFormularioEnviado(true);
              setTimeout(() => setFormularioEnviado(false), 5000);
				    }} >

            {( {values, touched, errors, handleSubmit, handleChange, handleBlur} ) => (
           
                <form className="formulario" onSubmit={handleSubmit}>
                   <div><h1 className="title">Form</h1></div>
                    <div>
                      <label htmlFor="nombre">Name</label>
                      <input 
                        type="text" 
                        id="nombre" 
                        name="nombre"
                        placeholder="Woody Allen" 
                        value={values.nombre}
                        onChange={handleChange}
                        onBlur={handleBlur}         
                     />
                     {touched.nombre && errors.nombre && <div className="error">{errors.nombre}</div>}
                    </div>

                    <div>
                      <label htmlFor="correo">Email</label>
                      <input 
                        type="text" 
                        id="correo" 
                        name="correo"
                        placeholder="contoso@domain.com"
                        value={values.correo}
                        onChange={handleChange}
                        onBlur={handleBlur}
                      />                    
                     {touched.correo && errors.correo && <div className="error">{errors.correo}</div>}
                    </div>
                    
                    <div>
                      <label htmlFor="password">Password</label>
                      <input 
                        type="password" 
                        id="password" 
                        name="password"
                        placeholder="Provide a password"
                        value={values.password}
                        onChange={handleChange}
                        onBlur={handleBlur}
                     />
                     {touched.password && errors.password && <div className="error">{errors.password}</div>}
                    </div>
                     
                    <div>
                    <Field name="mensaje" as="textarea" placeholder="Mensaje" />          
                    </div>                

                    <button type="submit">Submit</button>
                    {formularioEnviado && <p className="exito">Formulario enviado con exito!</p>}
                    
                </form>
            )}         
         </Formik>
      </>
    )
}

export default Formulario;