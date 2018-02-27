#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   lib_utility_macros.mk                              :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2018/01/10 13:12:16 by mgautier          #+#    #+#             *#
#*   Updated: 2018/01/10 16:35:35 by mgautier         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

ifndef LIB_UTILITY_MACROS_MK
LIB_UTILITY_MACROS_MK = $()

# Those macros idea come from :
# https://stackoverflow.com/a/665045/7208947
# (from user : https://stackoverflow.com/users/77345/eric-melski)
lower_case =$(subst A,a,$(subst B,b,$(subst C,c,$(subst D,d,\
$(subst E,e,$(subst\
F,f,$(subst G,g,$(subst H,h,$(subst I,i,$(subst J,j,$(subst K,k,$(subst\
L,l,$(subst M,m,$(subst N,n,$(subst O,o,$(subst P,p,$(subst Q,q,$(subst\
R,r,$(subst S,s,$(subst T,t,$(subst U,u,$(subst V,v,$(subst W,w,$(subst\
X,x,$(subst Y,y,$(subst Z,z,$1))))))))))))))))))))))))))

upper_case =$(subst a,A,$(subst b,B,$(subst c,C,$(subst d,D,\
$(subst e,E,$(subst\
f,F,$(subst g,G,$(subst h,H,$(subst i,I,$(subst j,J,$(subst k,K,$(subst\
l,L,$(subst m,M,$(subst n,N,$(subst o,O,$(subst p,P,$(subst q,Q,$(subst\
r,R,$(subst s,S,$(subst t,T,$(subst u,U,$(subst v,V,$(subst w,W,$(subst\
x,X,$(subst y,Y,$(subst z,Z,$1))))))))))))))))))))))))))

endif
