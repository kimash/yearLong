uniform sampler2DRect tex;

void main(void)
{
	vec3 rgb = texture2DRect(tex, gl_TexCoord[0].xy).rgb;
	gl_FragColor = vec4(1.-rgb, 1.);
}
